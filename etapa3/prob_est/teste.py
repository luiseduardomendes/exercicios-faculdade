from pprint import pprint
import sys

class App:
    def __init__(self) -> None:
        self.file_name = sys.argv[1]
        self.read_file()
        print(self.data)

    def read_file(self):
        with open(self.file_name) as f:
            self.data = []
            for line in f:
                self.data.append(line.replace('\n', '').split(','))

App()