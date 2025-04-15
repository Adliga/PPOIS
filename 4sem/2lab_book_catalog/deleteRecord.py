from recordFilter import *
class DeleteRecordDialog(BaseRecordFilterDialog):
    def __init__(self, records, delete_callback, parent=None):
        super().__init__(records, parent, exact_match=True)
        self.setWindowTitle("Удаление записей по условию")
        self.setFixedSize(400, 150)
        self.delete_callback = delete_callback

        self.layout = QVBoxLayout()

        self.criteria_label = QLabel("Выберите критерий:")
        self.layout.addWidget(self.criteria_label)
        self.layout.addWidget(self.criteria_combo)

        self.layout.addWidget(self.text_input)

        range_layout = QHBoxLayout()
        range_layout.addWidget(self.label_min)
        range_layout.addWidget(self.range_min)
        range_layout.addWidget(self.label_max)
        range_layout.addWidget(self.range_max)
        self.layout.addLayout(range_layout)

        button_layout = QHBoxLayout()
        delete_button = QPushButton("Удалить")
        delete_button.clicked.connect(self.handle_delete)
        cancel_button = QPushButton("Отмена")
        cancel_button.clicked.connect(self.reject)
        button_layout.addWidget(cancel_button)
        button_layout.addWidget(delete_button)
        self.layout.addLayout(button_layout)

        self.setLayout(self.layout)

    def handle_delete(self):
        """Обрабатывает удаление записей"""
        to_delete = self.filter_records()  
        if to_delete:
            self.delete_callback(to_delete, len(to_delete)) 
        else:
            self.delete_callback([], 0)  
        self.accept()