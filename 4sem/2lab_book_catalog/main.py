from libraries import *
from controller import BookController
from model import BookModel
from mainWindow import MainWindow

if __name__ == "__main__":
    app = QApplication(sys.argv)
    model = BookModel()
    controller = BookController(model, None)
    view = MainWindow(controller)
    controller.set_view(view)
    view.show()
    sys.exit(app.exec())