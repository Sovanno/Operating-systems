#include <Windows.h>
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    HANDLE stdin_handle, stdout_handle;
    DWORD bytes_to_read;
    char input_buffer[256];

    stdin_handle = GetStdHandle(STD_INPUT_HANDLE);
    stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);

    printf("Стандартный ввод: %d\n", (int)stdin_handle);
    printf("Стандартный вывод: %d\n", (int)stdout_handle);
    printf("Введите текст: ");
  
    if (ReadFile(stdin_handle, input_buffer, sizeof(input_buffer), &bytes_to_read, NULL))
    {
        WriteFile(stdout_handle, "Entered text: \n", sizeof("Entered text: "), NULL, NULL);
        WriteFile(stdout_handle, input_buffer, bytes_to_read, NULL, NULL);
    }

    return 0;
}
