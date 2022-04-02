from random import randint
from pandas import DataFrame

class new_test_ramses:

    def __init__(self, name: str):
        self.set_name(name)

        self.__init_lists__()

        self.__generate_random_values__()

        self.__split_vector_index_and_number__()

        self.sum = self.__set_sum__()

        self.__generate_excel_file__()

    def set_name(self, name):
        self.output_file = name

    def __init_lists__(self):
        self.v = []
        self.vi = []
        self.vn = []      

        index = 7 + randint(0,7)  

        for i in range(0,index):
            self.v.append(0);
        
        self.v.append(255);

    def __generate_random_values__(self):

        i = 0
        while self.v[i] != 255:
            self.v[i] = randint(0, 16) + randint(0,1) * 128
            i += 1

    def __split_vector_index_and_number__(self):
        i = 0
        self.size_index_vec = 0
        self.size_number_vec = 0
        while self.v[i] != 255:
            aux = self.v[i]
            if aux >= 128:
                aux = aux - 128;
                self.vi.append(aux)
                self.size_index_vec += 1
            
            elif aux <= 128:
            
                self.vn.append(aux)
                self.size_number_vec += 1
            
            i += 1

        vi_new = [i for i in self.vi if i < self.size_number_vec]
        self.vi.clear()
        self.vi = vi_new
        
        
    def __generate_excel_file__(self):
        for i in range(len(self.vn),len(self.v)):
            self.vn.append('')
        for i in range(len(self.vi),len(self.v)):
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

    def __set_sum__(self):
        sum = 0
        for cont in range (0, len(self.vi)):
            if self.vi[cont] < self.size_number_vec:
                sum += self.vn[self.vi[cont]]
            

        return sum

    def show_vector(self, v: list):
        for elem in v:
            print(f"{elem}  ", end='')
        
for i in range(0,50):
    generator_excel = new_test_ramses(f'excel_file{i}.xlsx')