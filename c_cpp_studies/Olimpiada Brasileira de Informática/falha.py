password_list = []
user_password_conflict = 0

registered_users = int(input())

for i in range(registered_users):
    password_list.append(input())

for i, password in enumerate(password_list):
    for j, bPassword in enumerate(password_list):
        if (i != j and bPassword in password):
            user_password_conflict += 1

print(user_password_conflict)