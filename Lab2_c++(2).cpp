#include <Windows.h>
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	HANDLE handle1, handle2, handle3;
	char buffer1[80], buffer2[80], buffer3[80];

	handle1 = CreateFile(L"file.txt", GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	DuplicateHandle(GetCurrentProcess(), handle1, GetCurrentProcess(), &handle2, 0, FALSE, DUPLICATE_SAME_ACCESS);

	handle3 = CreateFile(L"file.txt", GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	SetFilePointer(handle1, 10, 0, FILE_BEGIN);

	cout << "Первый хэндл: " << handle1 << endl;
	cout << "Второй хэндл: " << handle2 << endl;
	cout << "Третий хэндл: " << handle3 << endl;

	ReadFile(handle1, buffer1, 7, 0, 0);
	ReadFile(handle2, buffer2, 7, 0, 0);
	ReadFile(handle3, buffer3, 7, 0, 0);

	cout << "Текст, прочитанный через первый хэндл: " << string(buffer1, 7) << endl;
	cout << "Текст, прочитанный через второй хэндл: " << string(buffer2, 7) << endl;
	cout << "Текст, прочитанный через третий хэндл: " << string(buffer3, 7) << endl;

	CloseHandle(handle1);
	CloseHandle(handle2);
	CloseHandle(handle3);

	return 0;
}
