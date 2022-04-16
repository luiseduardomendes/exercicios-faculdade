from random import randint

n = 10
m = 2

list_removed = [2,3]

invited_list = []

for i in range(1, n+1):
    invited_list.append(i)

print(invited_list)

for num in list_removed:
    j = 1
    while (num-1)*j < len(invited_list):
        invited_list.pop((num - 1)* j)
        j += 1

    print(invited_list)
    input()

