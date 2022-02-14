from random import randint
from numpy import number

from pandas import DataFrame

class new_test_ramses:

    def __init__(self, name: str):
        
        self.set_name(name)
        
        self.init_lists()

        self.__generate_random_values__()

        self.split_vector_index_and_number()

        self.sum = self.set_sum()

        self.generate_excel_file()

    def set_name(self, name):
        self.output_file = name

    def init_lists(self):
        self.v = []
        self.vi = []
        self.vn = []        

        for i in range(0,15):
            self.v.append(0);

    def __generate_random_values__(self):

        self.v[7 + randint(0,7)] = 255

        i = 0
        while self.v[i] != 255:
            self.v[i] = randint(0, 16) + randint(0,1) * 128
            i += 1

    def split_vector_index_and_number(self):
        i = 0
        self.size_index_vec = 0
        self.size_number_vec = 0
        while self.v[i] != 255:
            aux = self.v[i]
            if aux >= 128:
                aux = aux - 128;
                self.vi.append(aux)
                self.size_index_vec += 1
            
            elif aux > 0 and aux <= 128 :
            
                self.vn.append(aux)
                self.size_number_vec += 1
            
            i += 1
        
    def generate_excel_file(self):
        for i in range(self.size_number_vec,len(self.v)):
            self.vn.append('')
        for i in range(self.size_index_vec,len(self.v)):
            self.vi.append('')

        soma_vector = []
        soma_vector.append(self.sum)
        for i in range(1,len(self.v)):
            soma_vector.append('')

        vectors = {
            'original_vector': self.v,
            'number_vector': self.vn,
            'index_vector': self.vi,
            'soma_total': soma_vector
        }
        
        DataFrame(vectors).to_excel(excel_writer=self.output_file)

    def set_sum(self):
        if self.size_number_vec < self.size_index_vec:
            min_value_size = self.size_number_vec
        else:
            min_value_size = self.size_index_vec

        sum = 0
        for cont in range (0, min_value_size):
            if self.vi[cont] < self.size_number_vec:
                sum += self.vn[self.vi[cont]]

        return sum

    def show_vector(self, v: list):
        for elem in v:
            print(f"{elem}  ", end='')
        
for i in range(0,100):
    generator_excel = new_test_ramses(f'excel_file{i}.xlsx')