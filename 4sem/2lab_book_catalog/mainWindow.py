from libraries import *
from model import *
from recordFilter import *
from paginatedTable import *
from searchDialog import *
from deleteRecord import *
from addRecord import *
from controller import *

class MainWindow(QMainWindow, PaginatedTableMixin):
    def __init__(self, controller):
        super().__init__()
        self.setWindowTitle("Книжный каталог")
        self.setGeometry(100, 100, 800, 440)
        
        self.setWindowIcon(QIcon("book_icon.png")) 

        self.setStyleSheet("""
            QMainWindow {
                background-color: #B2DFDB;  
            }
            QWidget {
                background-color: #B2DFDB;  
            }
            QTableWidget {
                background-color: #E6F3F2; 
                alternate-background-color: #CCECE9;  
                color: #000000; 
            }
            QTableWidget::item {
                border: 1px solid #B0BEC5;  
            }
            QHeaderView::section {
                background-color: #4DB6AC; 
                color: white;
                padding: 5px;
                border: 1px solid #00695C;
            }
            QPushButton {
                background-color: #4DB6AC;  
                color: white;
                border: 1px solid #00695C;
                padding: 5px;
                border-radius: 3px;
            }
            QPushButton:hover {
                background-color: #80CBC4;  
            }
            QLineEdit, QSpinBox, QComboBox {
                background-color: #FFFFFF;  
                border: 1px solid #4DB6AC;  
                padding: 3px;
                color: #000000;
            }
            QComboBox::drop-down {
                border-left: 1px solid #4DB6AC;
            }
            QLabel {
                color: #000000;  
                background-color: transparent;
            }
        """)
    
        self.controller = controller
        self.init_ui()

    def init_ui(self):
        self.create_menu()
        self.create_toolbar()
        self.create_table()

    def create_menu(self):
        menu = self.menuBar()
        file_menu = menu.addMenu("Меню")
        self.load_action = file_menu.addAction("Загрузить файл")
        self.save_action = file_menu.addAction("Сохранить файл")
        self.search_action = file_menu.addAction("Поиск записей")
        self.add_action = file_menu.addAction("Добавление записи")
        self.delete_action = file_menu.addAction("Удаление записей")
        file_menu.addSeparator()
        file_menu.addAction("Выход", self.close)

    def create_toolbar(self):
        toolbar = QToolBar("Основные действия")
        self.addToolBar(toolbar)

        self.load_action_tb = QAction("Загрузить", self)
        toolbar.addAction(self.load_action_tb)

        self.save_action_tb = QAction("Сохранить", self)
        toolbar.addAction(self.save_action_tb)

        self.search_action_tb = QAction("Поиск", self)
        toolbar.addAction(self.search_action_tb)

        self.add_action_tb = QAction("Добавить запись", self)
        toolbar.addAction(self.add_action_tb)

        self.delete_action_tb = QAction("Удалить запись", self)
        toolbar.addAction(self.delete_action_tb)

    def connect_actions(self, controller):
        self.load_action.triggered.connect(controller.load_data)
        self.save_action.triggered.connect(controller.save_data)
        self.search_action.triggered.connect(controller.open_search_dialog)
        self.add_action.triggered.connect(controller.open_add_record_dialog)
        self.delete_action.triggered.connect(controller.delete_record)

        self.load_action_tb.triggered.connect(controller.load_data)
        self.save_action_tb.triggered.connect(controller.save_data)
        self.search_action_tb.triggered.connect(controller.open_search_dialog)
        self.add_action_tb.triggered.connect(controller.open_add_record_dialog)
        self.delete_action_tb.triggered.connect(controller.delete_record)

    def create_table(self):
        central_widget = QWidget()
        self.setCentralWidget(central_widget)

        layout = QVBoxLayout()

        self.table = QTableWidget()
        self.table.setColumnCount(6)
        self.table.setHorizontalHeaderLabels(["Название", "Автор", "Издательство", "Число томов", "Тираж", "Итого томов"])
        self.table.setSizePolicy(QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding)
        header = self.table.horizontalHeader()
        for i in range(self.table.columnCount()):
            header.setSectionResizeMode(i, QHeaderView.ResizeMode.Stretch)
        layout.addWidget(self.table, stretch=1)

        self.init_pagination(layout)

        central_widget.setLayout(layout)

    def get_records_for_page(self):
        return self.controller.model.get_records()

    def update_table(self):
        self.update_table_with_records(self.table, self.get_records_for_page())