from addRecord import *
from searchDialog import *
from deleteRecord import *
from recordFilter import *
from model import *

class SearchController:
    def __init__(self, dialog):
        self.dialog = dialog

    def perform_search(self):
        if self.dialog:
            self.dialog.filter_records()
            self.dialog.current_page = 1
            self.dialog.page_selector.setValue(1)
            self.dialog.update_table()

class BookController:
    def __init__(self, model, view):
        self.model = model
        self.view = view
        self.current_file = None

    def set_view(self, view):
        """Устанавливает view и подключает действия."""
        self.view = view
        if self.view:
            print("Подключаем действия в MainWindow")
            self.view.connect_actions(self)
        else:
            print("View не установлен")

    def load_data(self):
        filename, _ = QFileDialog.getOpenFileName(
            self.view,
            "Выберите файл для загрузки",
            "",
            "XML Files (*.xml);;All Files (*)"
        )
        if filename:
            self.current_file = filename
            self.model.load_data_from_file(filename)
            self.view.update_table()
        else:
            print("Загрузка отменена пользователем")

    def save_data(self):
        if self.current_file:
            try:
                self.model.save_data_to_file(self.current_file)
                QMessageBox.information(
                    self.view,
                    "Сохранение данных",
                    f"Данные успешно сохранены в файл {self.current_file}.",
                    QMessageBox.StandardButton.Ok
                )
            except Exception as e:
                QMessageBox.critical(
                    self.view,
                    "Ошибка сохранения",
                    f"Не удалось сохранить данные: {str(e)}",
                    QMessageBox.StandardButton.Ok
                )
        else:
            filename, _ = QFileDialog.getSaveFileName(
                self.view,
                "Выберите файл для сохранения",
                "",
                "XML Files (*.xml);;All Files (*)"
            )
            if filename:
                self.current_file = filename
                try:
                    self.model.save_data_to_file(self.current_file)
                    QMessageBox.information(
                        self.view,
                        "Сохранение данных",
                        f"Данные успешно сохранены в файл {self.current_file}.",
                        QMessageBox.StandardButton.Ok
                    )
                except Exception as e:
                    QMessageBox.critical(
                        self.view,
                        "Ошибка сохранения",
                        f"Не удалось сохранить данные: {str(e)}",
                        QMessageBox.StandardButton.Ok
                    )
            else:
                QMessageBox.information(
                    self.view,
                    "Сохранение данных",
                    "Сохранение отменено.",
                    QMessageBox.StandardButton.Ok
                )

    def open_add_record_dialog(self):
        dialog = AddRecordDialog(self.view)
        if dialog.exec() == QDialog.DialogCode.Accepted:
            data = dialog.get_record()
            new_record = BookRecord(*data)
            self.model.add_record(new_record)
            self.view.current_page = 1
            self.view.page_selector.setValue(1)
            self.view.update_table()

    def open_search_dialog(self):
        search_dialog = SearchDialog(self.view, self.model)
        search_controller = SearchController(search_dialog)
        search_dialog.controller = search_controller
        search_dialog.exec()

    def delete_record(self):
        dialog = DeleteRecordDialog(self.model.get_records(), self.delete_selected_records, self.view)
        dialog.exec()

    def delete_selected_records(self, records_to_delete, count):
        if count > 0:
            for record in records_to_delete:
                self.model.remove_record(record)
            QMessageBox.information(
                self.view,
                "Удаление записей",
                f"Удалено {count} записей.",
                QMessageBox.StandardButton.Ok
            )
        else:
            QMessageBox.information(
                self.view,
                "Удаление записей",
                "Записи, соответствующие условиям, не найдены.",
                QMessageBox.StandardButton.Ok
            )
        self.view.update_table()