from libraries import *
class BookRecord:
    def __init__(self, title, author, publisher, volumes, circulation, total_volumes):
        self.title = title
        self.author = author
        self.publisher = publisher
        self.volumes = volumes
        self.circulation = circulation
        self.total_volumes = total_volumes

    def to_tuple(self):
        return (
            self.title, self.author, self.publisher,
            self.volumes, self.circulation, self.total_volumes
        )

class BookSAXHandler(xml.sax.ContentHandler):
    def __init__(self):
        super().__init__()
        self.records = []
        self.current_record = None
        self.current_tag = None
        self.title = ""
        self.author = ""
        self.publisher = ""
        self.volumes = 0
        self.circulation = 0
        self.total_volumes = 0

    def startElement(self, name, attrs):
        self.current_tag = name
        if name == "book":
            self.current_record = {}

    def endElement(self, name):
        if name == "book":
            record = BookRecord(
                self.title,
                self.author,
                self.publisher,
                self.volumes,
                self.circulation,
                self.total_volumes
            )
            self.records.append(record)
            self.title = ""
            self.author = ""
            self.publisher = ""
            self.volumes = 0
            self.circulation = 0
            self.total_volumes = 0
        self.current_tag = None

    def characters(self, content):
        if self.current_tag == "title":
            self.title = content.strip()
        elif self.current_tag == "author":
            self.author = content.strip()
        elif self.current_tag == "publisher":
            self.publisher = content.strip()
        elif self.current_tag == "volumes":
            self.volumes = int(content.strip())
        elif self.current_tag == "circulation":
            self.circulation = int(content.strip())
        elif self.current_tag == "total_volumes":
            self.total_volumes = int(content.strip())

class BookModel:
    def __init__(self):
        self.records = []

    def add_record(self, record: BookRecord):
        self.records.append(record)

    def get_records(self):
        return self.records
    
    def remove_record(self, record: BookRecord):
        if record in self.records:
            self.records.remove(record)

    def clear(self):
        self.records.clear()

    def load_data_from_file(self, filename):
        handler = BookSAXHandler()
        parser = xml.sax.make_parser()
        parser.setContentHandler(handler)
        try:
            parser.parse(filename)
            self.records = handler.records
            print(f"Загружено {len(self.records)} записей из файла {filename} с помощью SAX")
        except FileNotFoundError:
            self.records = []
            print(f"Файл {filename} не найден, список записей пуст")
        except xml.sax.SAXParseException as e:
            print(f"Ошибка парсинга XML: {e}")
            self.records = []

    def save_data_to_file(self, filename):
        root = ET.Element("books")
        for record in self.records:
            book_elem = ET.SubElement(root, "book")
            ET.SubElement(book_elem, "title").text = record.title
            ET.SubElement(book_elem, "author").text = record.author
            ET.SubElement(book_elem, "publisher").text = record.publisher
            ET.SubElement(book_elem, "volumes").text = str(record.volumes)
            ET.SubElement(book_elem, "circulation").text = str(record.circulation)
            ET.SubElement(book_elem, "total_volumes").text = str(record.total_volumes)
        tree = ET.ElementTree(root)
        tree.write(filename, encoding="utf-8", xml_declaration=True)

    def update_results(self):
        """Обновляет таблицу результатов"""
        self.result_table.setRowCount(0)
        for row, record in enumerate(self.filtered_records):
            self.result_table.insertRow(row)
            self.result_table.setItem(row, 0, QTableWidgetItem(record.title))
            self.result_table.setItem(row, 1, QTableWidgetItem(record.author))
            self.result_table.setItem(row, 2, QTableWidgetItem(record.publisher))
            self.result_table.setItem(row, 3, QTableWidgetItem(str(record.volumes)))
            self.result_table.setItem(row, 4, QTableWidgetItem(str(record.circulation)))
            self.result_table.setItem(row, 5, QTableWidgetItem(str(record.total_volumes)))