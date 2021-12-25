// contains main.cpp, fraction.cpp and fraction.h files
//operator overloading using memeber function
//main.cpp
#include "fraction.h"
#include <iostream>
using namespace std;
int main() {
    Fraction num1, num2, ans;
    char oper;
    num1.input();
    cin >> oper;
    num2.input();
    ans = num1;

    switch (oper) {
      case '+':
        ans = ans + num2; break;
      case '-':
        ans = ans - num2; break;
      case '*':
        ans = ans * num2; break;
      case '/':
        ans = ans / num2; break;
    }


    // display result
    cout << '(';
    num1.display();
    cout << ") "  << oper << " (";
    num2.display();
    cout << ") = ";
    ans.display();
    cout << endl;

    return 0;
}

// fraction.cpp

#include "fraction.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

/* find the greatest common divisor of two positive integers u,v. You may need this in implementing Fraction::reduce() */
int gcd(int u, int v) {
   int t;
   while (u > 0) {
      if(u < v) {
         t = u;
         u = v;
         v = t;
      }
      u = u-v;
   }
   return v;
}


void Fraction::reduce(){ 
    int divisor = gcd(abs(numer),abs(denom));
    numer /= divisor;
    denom /= divisor;
}

void Fraction::input(){
    char dummy;
    cin >> numer >> dummy >> denom;
    if (denom == 0) {
        cout << "dividing by zero\n";
        exit(1);
    }
}

void Fraction::display(){
    cout << numer << '/' << denom;
}

Fraction Fraction::operator +(Fraction &num2){
    int temp = denom;
    numer *= num2.denom;
    denom *= num2.denom;
    num2.numer *= temp;
    numer += num2.numer;
    num2.numer /= temp;
    reduce();
    Fraction ans;
    ans.numer = numer;
    ans.denom = denom;
    return ans;
}

Fraction Fraction::operator -(Fraction &num2){
    int temp = denom;
    numer *= num2.denom;
    denom *= num2.denom;
    num2.numer *= temp;
    numer -= num2.numer;
    num2.numer /= temp;
    reduce();
    Fraction ans;
    ans.numer = numer;
    ans.denom = denom;
    return ans;
}

Fraction Fraction::operator *(Fraction &num2){
    numer *= num2.numer;
    denom *= num2.denom;
    reduce();
    Fraction ans;
    ans.numer = numer;
    ans.denom = denom;
    return ans;
}
Fraction Fraction::operator /(Fraction &num2){
    if (num2.numer == 0) {
        cout << "dividing by zero\n";
        exit(1);
    }
    numer *= num2.denom;
    denom *= num2.numer;
    reduce();
    Fraction ans;
    ans.numer = numer;
    ans.denom = denom;
    return ans;
}

// fraction.h

#ifndef  FRACTION_H
#define  FRACTION_H

class Fraction {
public:
  void input();
	void display();     // display fraction
        //Since operator can only be used between two object, we declare one variable and use the class itself as another variable since it's a member function
	Fraction operator +(Fraction &frac2);
	Fraction operator -(Fraction &frac2); 
	Fraction operator *(Fraction &frac2);
  Fraction operator /(Fraction &frac2);  

private:
	void reduce();       
  /* reduce the fraction to its simplest form */
	int numer, denom;
};

#endif
