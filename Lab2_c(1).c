#include <Windows.h>
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    HANDLE file, input;
    DWORD size_of_input = 256, bytes_to_read;
    char input_buffer[256];
    BOOL wr;

    input = GetStdHandle(STD_INPUT_HANDLE);

    file = CreateFile(L"file.txt", GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);

    printf("Введите текст для записи в файл:");

    wr = ReadFile(input, input_buffer, size_of_input, &bytes_to_read, 0);

    WriteFile(file, input_buffer, bytes_to_read, 0, 0);

    printf("Файл успешно создан\n");

    CloseHandle(file);

    return 0;
}
