//include main.cpp, nthu.cpp and nthu.h

//main.cpp
#include <iostream>
#include "nthu.h"
using namespace std;


void input_data(NTHU_person &person1){
  person1.input();
  //person is of NTHU_person class
}

void output_data(NTHU_person &person1){
  person1.output();
}

int main() {
  NTHU_student joe;
  input_data(joe); 
  output_data(joe);

  NTHU_teacher cade;
  input_data(cade);
  output_data(cade);
  return 0;
} 

//nthu.h
#include <iostream>
#include <string>
using namespace std;

#ifndef NTHU_H
#define NTHU_H


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

/* modify this one as an abstract class */
class NTHU_person {
public:
    virtual void input() = 0;
    virtual void output() = 0;

protected:  
    string name;
    DayOfYear date_of_birth;
};


class NTHU_student : public NTHU_person {
public:
    NTHU_student();
    void output();
    void input();

private:
    string student_ID;
    string major;
};


class NTHU_teacher : public NTHU_person {
public:
    NTHU_teacher();
    void output();
    void input();

private:
    string employee_ID;
    string department;
};


#endif

//nthu.cpp

#include "nthu.h"
#include <iostream>
#include <string>
using namespace std;


DayOfYear::DayOfYear() {
    year = 0;
    month = 0;
    day = 0;
}

NTHU_student::NTHU_student(){
    student_ID = "\0";
    major = "\0";
}

NTHU_teacher::NTHU_teacher(){
    employee_ID = "\0";
    department = "\0";
}

void NTHU_student::input(){
    getline(cin, name);
    date_of_birth.input();
    cin.ignore();
    getline(cin, student_ID);
    getline(cin, major);
}

void NTHU_teacher::input(){
    getline(cin, name);
    date_of_birth.input();
    cin.ignore();
    getline(cin, employee_ID);
    getline(cin, department);
}

void NTHU_student::output(){
    cout << "<student>" << endl;

    for (string::iterator it = name.begin(); it != name.end(); ++it) {
        cout << *it;
    }
    cout << endl;

    date_of_birth.output();

    cout << "student ID number: ";
    for (int i = 0; i < student_ID.length(); ++i) {
        cout << student_ID.at(i);
    }
    cout << endl;
    
    cout << "major: ";
    for (int i = 0; i < major.length(); ++i) {
        cout << major.at(i);
    }
    cout << endl;
}

void NTHU_teacher::output(){
    cout << "<teacher>" << endl;

    for (string::iterator it = name.begin(); it != name.end(); ++it) {
        cout << *it;
    }
    cout << endl;

    date_of_birth.output();

    cout << "employee ID number: ";
    for (string::iterator it = employee_ID.begin(); it != employee_ID.end(); ++it) {
        cout << *it;
    }
    cout << endl;

    cout << "department: ";
    for (int i = 0; i < department.length(); ++i) {
        cout << department.at(i);
    }
    cout << endl;
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
