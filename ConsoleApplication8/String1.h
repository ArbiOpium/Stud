#pragma once
class String1
{
	char* str;
	int length;
	static int countLiveObj;
	static int countCreatedObj;
public:
	String1();
	String1(int size);
	String1(const char* initStr);
	String1(const String1& other);
	~String1();

	void MyStrcpy(String1& obj);
	bool MyStrStr(const char* substr);
	int MyChr(char c);
	int MyStrLen();
	void MyStrCat(String1& b);
	void MyDelChr(char c);
	int MyStrCmp(String1& b);

	void Print();
	void Input();

	static void GetCountLiveObj();
	static void GetCountCreatedObj();
};