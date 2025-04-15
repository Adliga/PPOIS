from libraries import *

class BaseRecordFilterDialog(QDialog):
    def __init__(self, records, parent=None, exact_match=False):
        super().__init__(parent)
        self.records = records
        self.filtered_records = []
        self.exact_match = exact_match

        self.criteria_combo = QComboBox()
        self.criteria_combo.addItems([
            "По ФИО автора",
            "По издательству",
            "По числу томов (диапазон)",
            "По названию книги",
            "Тираж (диапазон)",
            "Итого томов (диапазон)"
        ])

        self.text_input = QLineEdit()
        self.label_min = QLabel("Больше:")
        self.range_min = QSpinBox()
        self.range_min.setRange(0, 1000000)
        self.label_max = QLabel("Меньше:")
        self.range_max = QSpinBox()
        self.range_max.setRange(0, 1000000)

        self.criteria_combo.currentIndexChanged.connect(self.toggle_fields)

    def toggle_fields(self):
        """Показывает или скрывает поля ввода в зависимости от выбранного критерия"""
        index = self.criteria_combo.currentIndex()
        if index in [0, 1, 3]:  
            self.text_input.setVisible(True)
            self.label_min.setVisible(False)
            self.range_min.setVisible(False)
            self.label_max.setVisible(False)
            self.range_max.setVisible(False)
        else: 
            self.text_input.setVisible(False)
            self.label_min.setVisible(True)
            self.range_min.setVisible(True)
            self.label_max.setVisible(True)
            self.range_max.setVisible(True)

    def filter_records(self):
        """Фильтрует записи по выбранному критерию"""
        self.filtered_records.clear()
        criterion = self.criteria_combo.currentIndex()

        if criterion == 0: 
            value = self.text_input.text().strip().lower()
            if self.exact_match:
                self.filtered_records = [r for r in self.records if value == r.author.lower()]
            else:
                self.filtered_records = [r for r in self.records if value in r.author.lower()]
        elif criterion == 1:  
            value = self.text_input.text().strip().lower()
            if self.exact_match:
                self.filtered_records = [r for r in self.records if value == r.publisher.lower()]
            else:
                self.filtered_records = [r for r in self.records if value in r.publisher.lower()]
        elif criterion == 2:  
            min_val = self.range_min.value()
            max_val = self.range_max.value()
            self.filtered_records = [r for r in self.records if min_val < r.volumes < max_val]
        elif criterion == 3:  
            value = self.text_input.text().strip().lower()
            if self.exact_match:
                self.filtered_records = [r for r in self.records if value == r.title.lower()]
            else:
                self.filtered_records = [r for r in self.records if value in r.title.lower()]
        elif criterion == 4:  
            min_val = self.range_min.value()
            max_val = self.range_max.value()
            self.filtered_records = [r for r in self.records if min_val < r.circulation < max_val]
        elif criterion == 5: 
            min_val = self.range_min.value()
            max_val = self.range_max.value()
            self.filtered_records = [r for r in self.records if min_val < r.total_volumes < max_val]

        return self.filtered_records
