#include "String1.h"
#include <iostream>

using namespace std;

int String1::countLiveObj = 0;
int String1::countCreatedObj = 0;

String1::String1() {
	length = 80;
	str = new char[length + 1];
	for (size_t i = 0; i <= length; ++i) {
		str[i] = '\0';
	}

	countCreatedObj++;
	countLiveObj++;
}

String1::String1(int size) {
	if (size < 0) size = 0;
	length = size;
	str = new char[length + 1];
	for (int i = 0U; i <= length; ++i) { //0U unsigned
		str[i] = '\0';
	}

	countCreatedObj++;
	countLiveObj++;
}

String1::String1(const char* initStr) {
	if (initStr == nullptr) {
		length = 0;
		str = new char[1];
		str[0] = '\0';
	}
	else {
		length = strlen(initStr);
		str = new char[length + 1];
		strcpy_s(str, length + 1, initStr);
	}

	countCreatedObj++;
	countLiveObj++;
}

String1::String1(const String1& other)
{
	length = other.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, other.str);

	countCreatedObj++;
	countLiveObj++;
}

String1::~String1()
{
	delete[] str;
	countLiveObj--;
}


void String1::MyStrcpy(String1& obj)
{
	if (str == nullptr) return;
	delete[] obj.str;

	obj.length = length;
	obj.str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		obj.str[i] = str[i];
	}

	obj.str[length] = '\0';
}

bool String1::MyStrStr(const char* substr)
{
	if (str == nullptr or substr == nullptr) return false;

	for (int i = 0; str[i] != '\0'; i++)
	{
		int j = 0;

		while (substr[j] != '\0' and str[i + j] != '\0' and str[i + j] == substr[j]) {
			j++;
		}

		if (substr[j] == '\0') return true;
	}

	return false;
}

int String1::MyChr(char c)
{
	if (str == nullptr) return -1;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == c) {
			return i;
		}
	}

	return -1;
}

int String1::MyStrLen()
{
	if (str == nullptr) return 0;

	int length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return length;
}

void String1::MyStrCat(String1& b)
{
	if (str == nullptr) return;
	if (b.str == nullptr) return;

	int newLength = MyStrLen() + b.MyStrLen();
	char* newStr = new char[newLength + 1];

	int i = 0;
	for (; str[i] != '\0'; i++)
	{
		newStr[i] = str[i];
	}

	for (int j = 0; b.str[j] != '\0'; j++, i++)
	{
		newStr[i] = b.str[j];
	}

	newStr[newLength] = '\0';
	delete[] str;
	str = newStr;
	length = newLength;
}

void String1::MyDelChr(char c)
{
	if (str == nullptr) return;

	int j = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != c) {
			str[j++] = str[i];
		}
	}

	str[j] = '\0';
	length = j;
}

int String1::MyStrCmp(String1& b)
{
	if (str == nullptr && b.str == nullptr) return 0;
	if (str == nullptr) return -1;
	if (b.str == nullptr) return 1;

	int i = 0;
	while (str[i] != '\0' && b.str[i] != '\0')
	{
		if (str[i] < b.str[i]) return -1;
		if (str[i] > b.str[i]) return 1;
		i++;
	}

	if (str[i] == '\0' && b.str[i] == '\0') return 0;
	if (str[i] == '\0') return -1;
	return 1;
}

void String1::Print() {
	if (str == nullptr) {
		cout << "(null)" << endl;
	}
	else {
		cout << str << endl;
	}
}

void String1::Input()
{
	char buffer[1024];
	cout << "Enter a string: ";

	cin.getline(buffer, 1024);

	delete[] str;

	length = strlen(buffer);
	str = new char[length + 1];
	strcpy_s(str, length + 1, buffer);
}

void String1::GetCountLiveObj()
{
	cout << "Number of live objects: " << countLiveObj << endl;
}

void String1::GetCountCreatedObj()
{
	cout << "Total number of objects created: " << countCreatedObj << endl;
}
