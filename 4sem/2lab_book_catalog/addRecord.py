from recordFilter import *
class AddRecordDialog(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowTitle("Добавление книги")
        self.setGeometry(300, 300, 400, 250)

        layout = QVBoxLayout()

        self.title_input = QLineEdit()
        self.title_input.setPlaceholderText("Название книги")
        layout.addWidget(self.title_input)

        self.author_input = QLineEdit()
        self.author_input.setPlaceholderText("ФИО автора")
        layout.addWidget(self.author_input)

        self.publisher_input = QLineEdit()
        self.publisher_input.setPlaceholderText("Издательство")
        layout.addWidget(self.publisher_input)

        self.volumes_input = QSpinBox()
        self.volumes_input.setMinimum(1)
        self.volumes_input.setMaximum(100)
        self.volumes_input.setPrefix("Число томов: ")
        layout.addWidget(self.volumes_input)

        self.circulation_input = QSpinBox()
        self.circulation_input.setMinimum(1)
        self.circulation_input.setMaximum(1000000)
        self.circulation_input.setPrefix("Тираж: ")
        layout.addWidget(self.circulation_input)

        self.add_button = QPushButton("Добавить")
        self.add_button.clicked.connect(self.accept)
        layout.addWidget(self.add_button)

        self.setLayout(layout)
    
    def get_record(self):
        """Возвращает введённую запись, рассчитывая total_volumes автоматически"""
        volumes = self.volumes_input.value()
        circulation = self.circulation_input.value()
        total_volumes = volumes * circulation  

        return (
            self.title_input.text(),
            self.author_input.text(),
            self.publisher_input.text(),
            volumes,
            circulation,
            total_volumes
        )