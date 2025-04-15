from libraries import *
from recordFilter import BaseRecordFilterDialog
from paginatedTable import PaginatedTableMixin
class SearchDialog(BaseRecordFilterDialog, PaginatedTableMixin):
    def __init__(self, parent=None, model=None):
        super().__init__(model.get_records() if model else [], parent)
        self.setWindowTitle("Поиск записей")
        self.setGeometry(200, 200, 600, 400)

        self.model = model

        layout = QVBoxLayout()

        layout.addWidget(QLabel("Выберите критерий поиска:"))
        layout.addWidget(self.criteria_combo)

        layout.addWidget(QLabel("Введите значение для поиска:"))
        layout.addWidget(self.text_input)

        range_layout = QHBoxLayout()
        range_layout.addWidget(self.label_min)
        range_layout.addWidget(self.range_min)
        range_layout.addWidget(QLabel(" - "))
        range_layout.addWidget(self.label_max)
        range_layout.addWidget(self.range_max)
        layout.addLayout(range_layout)

        search_button = QPushButton("Искать")
        search_button.clicked.connect(self.perform_search)
        layout.addWidget(search_button)

        self.result_table = QTableWidget()
        self.result_table.setColumnCount(6)
        self.result_table.setHorizontalHeaderLabels(["Название", "Автор", "Издательство", "Число томов", "Тираж", "Итого томов"])
        self.result_table.setSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding)
        header = self.result_table.horizontalHeader()
        for i in range(self.result_table.columnCount()):
            header.setSectionResizeMode(i, QHeaderView.ResizeMode.Stretch)
        layout.addWidget(self.result_table, stretch=1)

        self.init_pagination(layout)

        self.setLayout(layout)

    def perform_search(self):
        """Выполняет поиск по выбранному критерию"""
        self.filter_records()
        self.current_page = 1
        self.page_selector.setValue(1)
        self.update_table()

    def get_records_for_page(self):
        """Возвращает отфильтрованные записи для текущей страницы."""
        return self.filtered_records

    def update_table(self):
        """Обновляет таблицу с учётом текущей страницы."""
        self.update_table_with_records(self.result_table, self.get_records_for_page())