//include main.cpp student.h student.cpp
//main.cpp
#include <iostream>
#include "student.h"
using namespace std;

int main() {
  student joe;
  joe.input_student();
  joe.output();
  return 0;
} 

//student.h
#include <iostream>
#include <string>
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H


class DayOfYear{
public:
  DayOfYear(int, int, int);
  DayOfYear();
  DayOfYear(DayOfYear&);
  void input();
  void output(); 
  
private:
  bool valid(int y, int m, int d); 
  int year;
  int month;
  int day;
};


class person {
public:
    person();
    void input();
    virtual void output();
    
protected:  
    string name;
    string ID_number;
    DayOfYear date_of_birth;
};


class student : public person {
public:
    student();
    void output() override;
    void input_student();

private:
    string student_ID;
    string major;
};


#endif

//student.cpp
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

person::person(){
    name = "\0";
    ID_number = "\0";
}

DayOfYear::DayOfYear() {
    year = 0;
    month = 0;
    day = 0;
}

student::student(){
    student_ID = "\0";
    major = "\0";
}

void student::input_student(){
    input();
    cin.ignore();
    getline(cin, student_ID);
    getline(cin, major);
}

void student::output(){
    cout << "Name: ";
    for (string::iterator it = name.begin(); it != name.end(); ++it) {
        cout << *it;
    }
    cout << endl;

    cout << "ID: ";
    for (int i = 0; i < ID_number.length(); ++i) {
        cout << ID_number.at(i);
    }
    cout << endl;
    
    date_of_birth.output();

    cout << "Stu ID: ";
    for (string::iterator it = student_ID.begin(); it != student_ID.end(); ++it) {
        cout << *it;
    }
    cout << endl;

    cout << "Major: ";
    for (int i = 0; i < major.length(); ++i) {
        cout << major.at(i);
    }
    cout << endl;
}

void person::input(){
    getline(cin, name);
    getline(cin, ID_number);
    date_of_birth.input();
}

void person::output(){
    for (string::iterator it = name.begin(); it != name.end(); ++it) {
        cout << *it;
    }
    cout << endl;

    for (int i = 0; i < ID_number.length(); ++i) {
        cout << ID_number.at(i);
    }
    cout << endl;

    date_of_birth.output();
}

void DayOfYear::input(){
    char dummy;
    cin >> year >> dummy >> month >> dummy >> day;
    
    
    if (!valid(year, month, day)) {
        cout << "Invalid input\n";
        exit(1);
    }
}

void DayOfYear::output() {
    cout << "DoB: ";
    cout << year << '/' << month << '/' << day << '\n';
}

bool DayOfYear::valid(int y, int m, int d){
    int cal[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m > 12) {
        return false;
    }
    if (m != 2) {
        return (d <= cal[m]);
    } else if (m == 2 && d <= 28) {
        return true;
    } else {
        if ( (((y % 100) && !(y % 4)) || !(y % 400)) && d == 29) {
            return true;
        } else {
            return false;
        }
    }
}
