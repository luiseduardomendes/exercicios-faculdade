from random import randint
from numpy import number

from pandas import DataFrame

for k in range (0,5):
    v = []
    vi = []
    vn = []

    for i in range(0,15):
        v.append(0);

    v[7 + randint(0,7)] = 255

    i = 0
    while v[i] != 255:
        v[i] = randint(0, 16) + randint(0,1) * 128
        i += 1


    i = 0
    print("Vetor original: ")
    while v[i] != 255 : 
        print(f"{v[i]}  ", end='')
        i += 1

    print("\n");

    i = 0
    size_index_vec = 0
    size_number_vec = 0
    while v[i] != 255:
        aux = v[i]
        if aux >= 128:
            aux = aux - 128;
            vi.append(aux)
            size_index_vec += 1
        
        elif aux > 0 and aux <= 128 :
        
            vn.append(aux)
            size_number_vec += 1
        
        i += 1

    print("Vetor de indices: ");
    for j in vi:
        print(f"{j}  ", end='')
    print("\n")

    print("Vetor de numeros: ");
    for j in vn:
        print(f"{j}  ", end='')
    print("\n")

    if size_number_vec < size_index_vec:
        min_value_size = size_number_vec
    else:
        min_value_size = size_index_vec

    soma = 0
    for cont in range (0, min_value_size):
        if vi[cont] < size_number_vec:
            soma += vn[vi[cont]]

    print(f"soma final: {soma}\n")

    for i in range(size_number_vec,len(v)):
        vn.append('')
    for i in range(size_index_vec,len(v)):
        vi.append('')

    soma_vector = []
    soma_vector.append(soma)
    for i in range(1,len(v)):
        soma_vector.append('')

    vectors = {
        'original_vector': v,
        'number_vector': vn,
        'index_vector': vi,
        'soma_total': soma_vector
    }

    excel_file = open(f'new_excel{k}.xlsx', 'w')
    data_frame = DataFrame(vectors).to_excel(excel_writer=f'new_excel{k}.xlsx')
    print(data_frame)