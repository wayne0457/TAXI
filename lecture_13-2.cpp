//contains main.cpp person.cpp person.h

//main.cpp

#include <iostream>
#include "person.h"
using namespace std;

int main() {
  person joe;
  joe.input();
  joe.output();
  return 0;
} 

//person.cpp

#include "person.h"
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

//person.h

#include <iostream>
#include <string>
using namespace std;

#ifndef PERSON_H
#define PERSON_H


class DayOfYear {
public:
  DayOfYear(int, int, int);
  DayOfYear();
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

#endif
