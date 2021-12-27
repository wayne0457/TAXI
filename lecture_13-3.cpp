// contains main.cpp, student.cpp and student.h

//main.cpp

#include <iostream>
#include "student.h"
using namespace std;

int main() {
  student joe;
  joe.input_student();
  joe.output_student();
  return 0;
} 

//student.cpp
/*
    if you encounter a problem like not inputting (getline) the correct string, you may use cin.ignore() 
    I'm not certain about how it works, but it works for me.
*/

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

void student::output_student(){
    output();
    for (string::iterator it = student_ID.begin(); it != student_ID.end(); ++it) {
        cout << *it;
    }
    cout << endl;

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
    void output();
    
private:  
    string name;
    string ID_number;
    DayOfYear date_of_birth;
};


class student : public person {
public:
    student();
    void output_student();
    void input_student();

private:
    string student_ID;
    string major;
};


#endif
