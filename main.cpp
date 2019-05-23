#include<iostream>
#include<Windows.h>
#include<conio.h>

//#define CASE_FUNCTIONS
using namespace std;

void InputLine(char szStr[], const int n);
int StrLen(char szStr[]);		//Определить длину строки символов.DONE
void UpperCase(char szStr[]);	//Переводит строку в верхний регистр.
void LowerCase(char szStr[]);	//Переводит строку в нижний  регистр.
void Capitalize(char szStr[]);  //Первая буква каждого слова в предложении делается заглавной
void ASCII();
bool isLowLetter(char symbol);
bool isLowRusLetter(char symbol);
void Shrink(char szStr[]);		//Удаляет лишние пробелы между словами в предложении.
void RemoveSpaces(char szStr[]);
bool isPalindrome(char szStr[]);	//Проверяет, является ли данная строка палиндромом.
bool isNumber(char szStr[]);	//Проверяет, является строка числом. Строка является числом, если содержит только цифры.
int stringToInt(char szStr[]);
bool isHexNumber(char szStr[]);	//Проверяет, является строка шестнадцатеричным числом. Строка является Hex-числом, если содержит только цифры и буквы ABCDEF либо abcdef.
int  Bin2Dec(char szStr[]);
int  Hex2Dec(char szStr[]);
void main()
{
	setlocale(LC_ALL, "");
	system("CHCP 1251");
	system("CLS");
	/*char szStr[] = {'H', 'e', 'l', 'l', 0};
	cout << szStr << endl;
	char szStr1[] = "Hell";
	cout << szStr1 << endl;*/
	const int n = 256;	//Размер строки
	char szStr[n] = {};
	cout << "Введите строку: ";
	//InputLine(szStr, n);
	//cin >> szStr;
	cin.getline(szStr, n);
	/*Shrink(szStr);
	cout << szStr << endl;*/
	//cout << isPalindrome(szStr) << endl;
	//cout << isNumber(szStr) << endl;
	//cout << stringToInt(szStr) << endl;
	cout << isHexNumber(szStr) << endl;



#ifdef CASE_FUNCTIONS
	cout << szStr << endl;
	cout << StrLen(szStr) << endl;
	UpperCase(szStr);
	cout << szStr << endl;
	LowerCase(szStr);
	cout << szStr << endl;
	Capitalize(szStr);
	cout << szStr << endl;
	Shrink(szStr);
	cout << szStr << endl;

	//ASCII();
	/*do
	{
		cout << getch() << endl;
	} while (getch() != 27);*/
#endif 

}
void ASCII()
{
	for (int i = 0; i < 256; i++)
	{
		cout << char(i) << " " << i << endl;

	}
}
void InputLine(char szStr[], const int n)
{
	//cout << typeid(szStr).name() << endl;
	SetConsoleCP(1251);
	cin.getline(szStr, n);
	SetConsoleCP(867);
}
int StrLen(char szStr[])
{
	int i = 0;
	for (; szStr[i]; i++);
	return i;
}
void UpperCase(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{
		if (
			szStr[i] >= 'a' && szStr[i] <= 'z' ||
			szStr[i] >= 'а' && szStr[i] <= 'я'
			)
			szStr[i] -= 32;
	}
}
void LowerCase(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{

		if (
			szStr[i] >= 'A' && szStr[i] <= 'Z' ||
			szStr[i] >= 'А' && szStr[i] <= 'Я'
			)
			szStr[i] += 32;




	}
}
void Capitalize(char szStr[])
{
	LowerCase(szStr);
	/*if (
		szStr[0] >= 'a' && szStr[0] <= 'z' ||
		szStr[0] >= 'а' && szStr[0] <= 'я'
		)
		szStr[0] -= 32;
	for (int i = 1; szStr[i]; i++)
	{

		if (szStr[i] == 32)
		{
			i++;
			if(
				szStr[i] >= 'a' && szStr[i] <= 'z' ||
				szStr[i] >= 'а' && szStr[i] <= 'я'
			  )
			{
			szStr[i] -= 32;
			}

		}
	}*/
	if (isLowLetter(szStr[0]) || isLowRusLetter(szStr[0]))szStr[0] -= 32;
	for (int i = 0; szStr[i]; i++)
	{
		if (szStr[i - 1] == ' ' && (isLowLetter(szStr[i]) || isLowRusLetter(szStr[i])))
			szStr[i] -= 32;
	}
}
bool isLowLetter(char symbol)
{
	if (symbol >= 'a' && symbol <= 'z')return true;
	else return false;
}
bool isLowRusLetter(char symbol)
{
	if (symbol >= 'а' && symbol <= 'я')return true;
	else return false;
}
void Shrink(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{
		while (szStr[i] == 32 && szStr[i + 1] == 32)
		{
			for (int j = i + 1; szStr[j]; j++)
			{
				szStr[j] = szStr[j + 1];
			}
		}
	}
}
bool isPalindrome(char szStr[])
{
	int size = StrLen(szStr);
	char* buffer = new char[size + 1]{};
	for (int i = 0; i < size; i++)buffer[i] = szStr[i];
	LowerCase(buffer);
	RemoveSpaces(buffer);
	size = StrLen(buffer);
	//bool truth = false;
	for (int i = 0; i < size / 2; i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			//truth = true;
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}
void RemoveSpaces(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{
		while (szStr[i] == 32)
		{
			for (int j = i; szStr[j]; j++)
			{
				szStr[j] = szStr[j + 1];
			}
		}
	}

}
bool isNumber(char szStr[])
{
	if ((szStr[0]<'0' || szStr[0]>'9') && szStr[0] != '-'&&szStr[0] != '+')return false;
	for (int i = 1; szStr[i]; i++)
	{
		if (szStr[i]<'0' || szStr[i]>'9')return false;
	}
	return true;
}
bool isHexNumber(char szStr[])
{
	for (int i = 0; szStr[i]; i++)
	{
		if ((szStr[i]<'0' || szStr[i]>'9')&&szStr[i]!='-'&&szStr[i]!='+'&&((szStr[i]<'a'&&szStr[i]>'f')|| (szStr[i] < 'A'&&szStr[i] > 'F')))return false;
	}
	return true;
}
int stringToInt(char szStr[])
{
	if (!isNumber(szStr))return 0;
	int decimal = 0;
	int i = 0;
	if (szStr[0] == '-'|| szStr[0] == '+')i++;
	for (; szStr[i]; i++)
	{
		decimal *= 10;
		decimal += szStr[i] - 48;

	}
	if (szStr[0] == '-')decimal = -decimal;
	return decimal;
}