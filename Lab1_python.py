import sys

stdin_handle = sys.stdin.fileno()
stdout_handle = sys.stdout.fileno()

print("Стандартный ввод:", stdin_handle)
print("Стандартный вывод:", stdout_handle)

print("Введите колличество символов:")
a = int(input())

input_buffer = bytearray(a)

sys.stdout.write("Введите текст: ")
sys.stdout.flush()

bytes_read = sys.stdin.buffer.readinto(input_buffer)

if bytes_read > 0:
    sys.stdout.write("Введенный текст: ")
    sys.stdout.flush()
    sys.stdout.buffer.write(input_buffer[:bytes_read])
