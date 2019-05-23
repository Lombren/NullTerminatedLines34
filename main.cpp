#include<iostream>
#include<Windows.h>
#include<conio.h>

//#define CASE_FUNCTIONS
using namespace std;

void InputLine(char szStr[], const int n);
int StrLen(char szStr[]);		//���������� ����� ������ ��������.DONE
void UpperCase(char szStr[]);	//��������� ������ � ������� �������.
void LowerCase(char szStr[]);	//��������� ������ � ������  �������.
void Capitalize(char szStr[]);  //������ ����� ������� ����� � ����������� �������� ���������
void ASCII();
bool isLowLetter(char symbol);
bool isLowRusLetter(char symbol);
void Shrink(char szStr[]);//������� ������ ������� ����� ������� � �����������.
void RemoveSpaces(char szStr[]);
bool isPalindrome(char szStr[]);	//���������, �������� �� ������ ������ �����������.
bool isNumber(char szStr[]);	//���������, �������� ������ ������. ������ �������� ������, ���� �������� ������ �����.
bool isHexNumber(char szStr[]);	//���������, �������� ������ ����������������� ������. ������ �������� Hex-������, ���� �������� ������ ����� � ����� ABCDEF ���� abcdef.

void main()
{
	setlocale(LC_ALL, "");
	system("CHCP 1251");
	system("CLS");
	/*char szStr[] = {'H', 'e', 'l', 'l', 0};
	cout << szStr << endl;
	char szStr1[] = "Hell";
	cout << szStr1 << endl;*/
	const int n = 256;	//������ ������
	char szStr[n] = {};
	cout << "������� ������: ";
	//InputLine(szStr, n);
	//cin >> szStr;
	cin.getline(szStr, n);
	Shrink(szStr);
	cout << szStr << endl;
	cout << isPalindrome(szStr) << endl;


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
			szStr[i] >= '�' && szStr[i] <= '�'
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
			szStr[i] >= '�' && szStr[i] <= '�'
			)
			szStr[i] += 32;




	}
}
void Capitalize(char szStr[])
{
	LowerCase(szStr);
	/*if (
		szStr[0] >= 'a' && szStr[0] <= 'z' ||
		szStr[0] >= '�' && szStr[0] <= '�'
		)
		szStr[0] -= 32;
	for (int i = 1; szStr[i]; i++)
	{

		if (szStr[i] == 32)
		{
			i++;
			if(
				szStr[i] >= 'a' && szStr[i] <= 'z' ||
				szStr[i] >= '�' && szStr[i] <= '�'
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
	if (symbol >= '�' && symbol <= '�')return true;
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
	for (int i = 0; i<size/2; i++)
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