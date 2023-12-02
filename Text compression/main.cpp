#include<iostream>
#include<Windows.h>

using namespace std;

// В строке текста записаны слова, разделенные пробелами в произвольном
// количестве.Сжатие текста состоит в том, что между словами оставляется
// по одному пробелу,а после последнего слова пробелы удаляются
// (пробелы перед первым словом сохраняются).Если строка содержит 
// только пробелы,то все они сохраняются. Написать функцию, сжимающую текст.

void compress(char* str) 
{
	char temp[256]{};
	temp[0] = '\0';
	int i{ 0 }, j{ 0 };
	int state = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ' && !state)
		{
			temp[j] = str[i];
			j++;
		}
		else if (str[i] != ' ' && state <= 1)
		{
			state = 1;
			temp[j] = str[i];
			j++;
		}
		else if (str[i] == ' ' && state == 1)
		{
			state = 2;
		}
		else if (str[i] != ' ' && state == 2)
		{
			state = 1;
			temp[j] = ' ';
			j++;
			temp[j] = str[i];
			j++;
		}
	}
	temp[j] = '\0';
	cout << "Получившийся текст: ";
	puts(temp);
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char str_one[256];
	cout << "Введите текст\t  : ";
	gets_s(str_one);

	compress(str_one);

	return 777;
}