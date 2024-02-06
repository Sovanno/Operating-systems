import sys
from win32file import CreateFile, GENERIC_READ, FILE_SHARE_READ, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, SetFilePointer, ReadFile

file_handle = CreateFile("file.txt", GENERIC_READ, FILE_SHARE_READ, None, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, None)

handle2 = file_handle

file_handle2 = CreateFile("file.txt", GENERIC_READ, FILE_SHARE_READ, None, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, None)

SetFilePointer(file_handle, 10, 0)

print(f"Первый хэндл: {hex(int(file_handle))}")
print(f"Второй хэндл: {hex(int(handle2))}")
print(f"Третий хэндл: {hex(int(file_handle2))}")

buffer1 = bytearray(7)
ReadFile(file_handle, buffer1)

buffer2 = bytearray(7)
ReadFile(handle2, buffer2)

buffer3 = bytearray(7)
ReadFile(file_handle2, buffer3)

text1 = buffer1.decode("utf-8").strip()
text2 = buffer2.decode("utf-8").strip()
text3 = buffer3.decode("utf-8").strip()

print(f"Текст, прочитанный через первый хэндл: {text1}")
print(f"Текст, прочитанный через второй хэндл: {text2}")
print(f"Текст, прочитанный через третий хэндл: {text3}")

file_handle.close()
handle2.close()
file_handle2.close()
