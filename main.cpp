#include<iostream>
#include<Windows.h>
#include<conio.h>

//#define CASE_FUNCTIONS
using namespace std;

void InputLine(char szStr[], const int n);
int StrLen(char szStr[]);		//Определить длину строки символов.DONE
void UpperCase(char szStr[]);	//Переводит строку в верхний регистр.DONE
void LowerCase(char szStr[]);	//Переводит строку в нижний  регистр.DONE
void Capitalize(char szStr[]);  //Первая буква каждого слова в предложении делается заглавной.DONE
void ASCII();//DONE
bool isLowLetter(char symbol);//DONE
bool isLowRusLetter(char symbol);//DONE
void Shrink(char szStr[]);		//Удаляет лишние пробелы между словами в предложении.DONE
void RemoveSpaces(char szStr[]);//DONE
bool isPalindrome(char szStr[]);	//Проверяет, является ли данная строка палиндромом.DONE
bool isNumber(char szStr[]);	//Проверяет, является строка числом. Строка является числом, если содержит только цифры.DONE
int stringToInt(char szStr[]);//DONE
bool isHexNumber(char szStr[]);	//Проверяет, является строка шестнадцатеричным числом. Строка является Hex-числом, если содержит только цифры и буквы ABCDEF либо abcdef.DONE
bool isBinNumber(char szStr[]);//DONE
int  Bin2Dec(char szStr[]);//DONE
int  Hex2Dec(char szStr[]);//вроде DONE
void main()
{
	//setlocale(LC_ALL, "");
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
	//cout << isHexNumber(szStr) << endl;
	//cout << isBinNumber(szStr) << endl;
	//ASCII();
	cout << "Количество елементов строки: " << StrLen(szStr) << endl;
	cout << "Bin to Decimal: " << Bin2Dec(szStr) << endl;
	cout << "Hex to Decimal: " << Hex2Dec(szStr) << endl;



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
		if (!(szStr[i] >= '0'&&szStr[i] <= '9') &&
			!(szStr[i] >= 'A'&&szStr[i] <= 'F') &&
			!(szStr[i] >= 'a'&&szStr[i] <= 'f')
			)return false;
	}
	return true;
}
bool isBinNumber(char szStr[])
{
	int n = StrLen(szStr);
	char* Buffer = new char[n + 1]{};
	for (int i = 0; szStr[i]; i++)
	{
		Buffer[i] = szStr[i];
	}
	RemoveSpaces(Buffer);
	for (int i = 0; Buffer[i]; i++)
	{
		if (Buffer[i] != '0' && Buffer[i] != '1')
		{
			delete[] Buffer;
			return false;
		}
	}
	delete[] Buffer;
	return true;
}
int stringToInt(char szStr[])
{
	if (!isNumber(szStr))return 0;
	int decimal = 0;
	int i = 0;
	if (szStr[0] == '-' || szStr[0] == '+')i++;
	for (; szStr[i]; i++)
	{
		decimal *= 10;
		decimal += szStr[i] - 48;

	}
	if (szStr[0] == '-')decimal = -decimal;
	return decimal;
}
int  Bin2Dec(char szStr[])
{
	if (!isBinNumber(szStr))
	{
		cout << "Error: not binary" << endl;
		return 0;
	}
	int n = StrLen(szStr);
	int Dec = 0;
	int step = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (szStr[i] == ' ')continue;
		Dec += (szStr[i] - 48) * step;
		step *= 2;
	}
	return Dec;

}
int  Hex2Dec(char szStr[])
{
	if (!isHexNumber(szStr))
	{
		cout << "Error: not Hex" << endl;
		return 0;
	}
	/*int n = StrLen(szStr);
	char* Buffer = new char[n + 1]{};
	for (int i = 0; szStr[i]; i++)
	{
		Buffer[i] = szStr[i];
	}
	for (int i = 0; Buffer[i]; i++)
	{
		if (Buffer[i] >= 'A'&&Buffer[i] <= 'F')Buffer[i] = Buffer[i] - 7;
		if (Buffer[i] >= 'a'&&Buffer[i] <= 'f')Buffer[i] = Buffer[i] - 39;
	}
	int Dec = 0;
	int step = 1;
	for (int i = n - 1; i >= 0; i--)
	{

		if (Buffer[i] == ' ')continue;
		Dec += (Buffer[i] - 48) * step;
		step *= 16;
	}*/
	int Dec = 0;
	int weight = 1;
	for (int i = StrLen(szStr) - 1; i >= 0; i--)
	{
		Dec += (szStr[i] > 'a' ? szStr[i] - 87 : szStr[i] > 'A' ? szStr[i] - 55 : szStr[i] - 48)*weight;
		weight *= 16;
	}
	return Dec;

}