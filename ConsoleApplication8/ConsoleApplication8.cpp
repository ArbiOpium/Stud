#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

class Student {
    char* name;
    char* surname;
    char* patronymic;

    int day;
    int month;
    int year;

    int phoneNum;

    char* country;

    char* university;
    int groupNum;

public:
    // Конструкторы и деструктор
    Student() : name(nullptr), surname(nullptr), patronymic(nullptr),
        day(0), month(0), year(0), phoneNum(0),
        country(nullptr), university(nullptr), groupNum(0) {}
    Student(const char* name1, const char* surname1, const char* patronymic1,
        int d, int m, int y, int phone,
        const char* country1, const char* university1, int g) 
    {
        name = new char[strlen(name1) + 1];
        strcpy_s(name, strlen(name1) + 1, name1);

        surname = new char[strlen(surname1) + 1];
        strcpy_s(surname, strlen(surname1) + 1, surname1);

        patronymic = new char[strlen(patronymic1) + 1];
        strcpy_s(patronymic, strlen(patronymic1) + 1, patronymic1);

        day = d;
        month = m;
        year = y;

        phoneNum = phone;

        country = new char[strlen(country1) + 1];
        strcpy_s(country, strlen(country1) + 1, country1);

        university = new char[strlen(university1) + 1];
        strcpy_s(university, strlen(university1) + 1, university1);

        groupNum = g;
    }
    ~Student() 
    {
        delete[] name;
        delete[] surname;
        delete[] patronymic;
        delete[] country;
        delete[] university;
    }

    // Сеттеры
    void setName(const char* name1) {
        if (name != nullptr) {
            delete[] name;
        }
        name = new char[strlen(name1) + 1];
        strcpy_s(name, strlen(name1) + 1, name1);
    }
    void setSurname(const char* surname1) {
        if (surname != nullptr) {
            delete[] surname;
        }
        surname = new char[strlen(surname1) + 1];
        strcpy_s(surname, strlen(surname1) + 1, surname1);
    }
    void setPatronymic(const char* patronymic1) {
        if (patronymic != nullptr) {
            delete[] patronymic;
        }
        patronymic = new char[strlen(patronymic1) + 1];
        strcpy_s(patronymic, strlen(patronymic1) + 1, patronymic1);
    }
    void setDay(int d) {
        day = d;
    }
    void setMonth(int m) {
        month = m;
    }
    void setYear(int y) {
        year = y;
    }
    void setPhoneNum(int pn) {
        phoneNum = pn;
    }
    void setCountry(const char* country1) {
        if (country != nullptr) {
            delete[] country;
        }
        country = new char[strlen(country1) + 1];
        strcpy_s(country, strlen(country1) + 1, country1);
    }
    void setUniversity(const char* university1) {
        if (university != nullptr) {
            delete[] university;
        }
        university = new char[strlen(university1) + 1];
        strcpy_s(university, strlen(university1) + 1, university1);
    }
    void setGroupNum(int gn) 
    {
        groupNum = gn;
    }

    // Геттеры
    const char* getName() const 
    {
        return name;
    }
    const char* getSurname() const 
    {
        return surname;
    }
    const char* getPatronymic() const 
    {
        return patronymic;
    }
    int getDay() const 
    {
        return day;
    }
    int getMonth() const 
    {
        return month;
    }
    int getYear() const 
    {
        return year;
    }
    int getPhoneNum() const 
    {
        return phoneNum;
    }
    const char* getCountry() const 
    {
        return country;
    }
    const char* getUniversity() const 
    {
        return university;
    }
    int getGroupNum() const 
    {
        return groupNum;
    }

    // Функции
    void Input() {
        char bufferName[100];
        char bufferSurname[100];
        char bufferPatronymic[100];
        char bufferCountry[100];
        char bufferUniversity[100];

        cout << "Enter name: ";
        cin.ignore();
        cin.getline(bufferName, 100);

        cout << "Enter surname: ";
        cin.getline(bufferSurname, 100);

        cout << "Enter patronymic: ";
        cin.getline(bufferPatronymic, 100);

        cout << "Enter day: ";
        cin >> day;
        cin.ignore();

        cout << "Enter month: ";
        cin >> month;
        cin.ignore();

        cout << "Enter year: ";
        cin >> year;
        cin.ignore();

        cout << "Enter phone number: ";
        cin >> phoneNum;
        cin.ignore();

        cout << "Enter country: ";
        cin.getline(bufferCountry, 100);

        cout << "Enter university: ";
        cin.getline(bufferUniversity, 100);

        cout << "Enter group number: ";
        cin >> groupNum;
        cin.ignore();

        setName(bufferName);
        setSurname(bufferSurname);
        setPatronymic(bufferPatronymic);
        setCountry(bufferCountry);
        setUniversity(bufferUniversity);
    }
    void PrintStudent() const 
    {
        if (name != nullptr) cout << "Name: " << name << endl;
        else cout << "Name: N/A" << endl;

        if (surname != nullptr) cout << "Surname: " << surname << endl;
        else cout << "Surname: N/A" << endl;

        if (patronymic != nullptr) cout << "Patronymic: " << patronymic << endl;
        else cout << "Patronymic: N/A" << endl;

        cout << "Date of Birth: " << day << "/" << month << "/" << year << endl;

        cout << "Phone Number: " << phoneNum << endl;

        if (country != nullptr) cout << "Country: " << country << endl;
        else cout << "Country: N/A" << endl;

        if (university != nullptr) cout << "University: " << university << endl;
        else cout << "University: N/A" << endl;

        cout << "Group Number: " << groupNum << endl;
    }
};

int main() 
{
    Student student1("Antoha"," Sergeev", "Antipov", 10, 2, 1996, 777-666-555, "UKR", "STEP", 200);
    student1.PrintStudent();

    Student student2;
    student2.Input();
    student2.PrintStudent();

    system("pause");
    return 0;
}