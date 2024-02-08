#include <stdio.h>
#include <windows.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    HANDLE handle1, handle2, handle3;
    char buffer1[80], buffer2[80], buffer3[80];

    handle1 = CreateFile(L"file.txt", GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    DuplicateHandle(GetCurrentProcess(), handle1, GetCurrentProcess(), &handle2, 0, FALSE, DUPLICATE_SAME_ACCESS);

    handle3 = CreateFile(L"file.txt", GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    SetFilePointer(handle1, 10, 0, FILE_BEGIN);

    printf("Первый хэндл: %p\n", handle1);
    printf("Второй хэндл: %p\n", handle2);
    printf("Третий хэндл: %p\n", handle3);

    ReadFile(handle1, buffer1, 7, 0, 0);
    ReadFile(handle2, buffer2, 7, 0, 0);
    ReadFile(handle3, buffer3, 7, 0, 0);

    printf("Текст, прочитанный через первый хэндл: %.*s\n", 7, buffer1);
    printf("Текст, прочитанный через второй хэндл: %.*s\n", 7, buffer2);
    printf("Текст, прочитанный через третий хэндл: %.*s\n", 7, buffer3);

    CloseHandle(handle1);
    CloseHandle(handle2);
    CloseHandle(handle3);

    return 0;
}
