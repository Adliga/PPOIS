from libraries import *
class PaginatedTableMixin:
    def init_pagination(self, layout):
        """Инициализирует элементы управления постраничным выводом и добавляет их в layout."""
        self.current_page = 1
        self.records_per_page = 10

        page_layout = QHBoxLayout()

        first_button = QPushButton("Первая")
        first_button.clicked.connect(self.first_page)
        page_layout.addWidget(first_button)

        prev_button = QPushButton("<<")
        prev_button.clicked.connect(self.prev_page)
        page_layout.addWidget(prev_button)

        self.page_selector = QSpinBox()
        self.page_selector.setMinimum(1)
        self.page_selector.valueChanged.connect(self.change_page)
        page_layout.addWidget(self.page_selector)

        next_button = QPushButton(">>")
        next_button.clicked.connect(self.next_page)
        page_layout.addWidget(next_button)

        last_button = QPushButton("Последняя")
        last_button.clicked.connect(self.last_page)
        page_layout.addWidget(last_button)

        page_size_layout = QHBoxLayout()
        page_size_label = QLabel("Записей на странице:")
        self.page_size_selector = QSpinBox()
        self.page_size_selector.setMinimum(1)
        self.page_size_selector.setMaximum(100)
        self.page_size_selector.setValue(self.records_per_page)
        self.page_size_selector.valueChanged.connect(self.change_page_size)
        page_size_layout.addWidget(page_size_label)
        page_size_layout.addWidget(self.page_size_selector)
        page_layout.addLayout(page_size_layout)

        self.page_info_label = QLabel()
        page_layout.addWidget(self.page_info_label)
        page_layout.addStretch()

        layout.addLayout(page_layout, stretch=0)
        self.update_page_info()

    def get_records_for_page(self):
        """Абстрактный метод, должен быть переопределён в дочерних классах."""
        raise NotImplementedError("Метод get_records_for_page должен быть переопределён в дочернем классе")

    def update_table_with_records(self, table, records):
        """Обновляет таблицу с учётом текущей страницы."""
        table.setRowCount(0)
        start = (self.current_page - 1) * self.records_per_page
        end = start + self.records_per_page
        page_records = records[start:end]

        for row, record in enumerate(page_records):
            table.insertRow(row)
            for col, value in enumerate(record.to_tuple()):
                table.setItem(row, col, QTableWidgetItem(str(value)))

        self.update_page_info()

    def update_page_info(self):
        """Обновляет информацию о страницах."""
        total_records = len(self.get_records_for_page())
        total_pages = max(1, math.ceil(total_records / self.records_per_page))
        self.page_info_label.setText(
            f"   Всего записей: {total_records}     |     "
            f"Страница {self.current_page} из {total_pages}"
        )
        self.page_selector.setMaximum(total_pages)

    def change_page(self, value):
        self.current_page = value
        self.update_table()

    def prev_page(self):
        if self.current_page > 1:
            self.current_page -= 1
            self.page_selector.setValue(self.current_page)

    def next_page(self):
        total_records = len(self.get_records_for_page())
        total_pages = max(1, math.ceil(total_records / self.records_per_page))
        if self.current_page < total_pages:
            self.current_page += 1
            self.page_selector.setValue(self.current_page)

    def first_page(self):
        self.current_page = 1
        self.page_selector.setValue(self.current_page)

    def last_page(self):
        total_records = len(self.get_records_for_page())
        total_pages = max(1, math.ceil(total_records / self.records_per_page))
        self.current_page = total_pages
        self.page_selector.setValue(self.current_page)

    def change_page_size(self, value):
        self.records_per_page = value
        self.current_page = 1  
        self.page_selector.setValue(1)
        self.update_table()