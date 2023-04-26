from pprint import pprint
from random import randint as rand

silabas = [
    'he', 'lo',
    'bol', 'son',
    'vi', 'ni',
    'na', 'than',
    'lu', 'is',
    'me', 'nin',
    'pe', 'dro',
    'hen', 'ry',
    'ever', 'ton'
]

def get_silaba():
    i = rand(0, len(silabas)-1)
    ret = silabas[i][:]
    del silabas[i]
    return ret

names = {
    'helo':'',
    'luis':'',
    'vini':'',
    'menin':'',
    'bolson':'',
    'nathan':'',
    'pedro':'',
    'henry':'',
    'everton':''
}
for name in names.keys():
    names[name] = get_silaba() + get_silaba()

pprint(names)