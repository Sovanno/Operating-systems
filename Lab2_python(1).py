import sys

with open("file.txt", "w", encoding="utf-8") as file:
    text = sys.stdin.read()
    file.write(text)

print("Файл успешно создан")
