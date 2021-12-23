// contains main.cpp fraction.cpp and fraction.h files

// main.cpp
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

//fraction.cpp
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

Fraction operator +(Fraction &num1, Fraction &num2){
    int temp = num1.denom;
    num1.numer *= num2.denom;
    num1.denom *= num2.denom;
    num2.numer *= temp;
    num1.numer += num2.numer;
    num2.numer /= temp;
    num1.reduce();
    return num1;
}

Fraction operator -(Fraction &num1, Fraction &num2){
    int temp = num1.denom;
    num1.numer *= num2.denom;
    num1.denom *= num2.denom;
    num2.numer *= temp;
    num1.numer -= num2.numer;
    num2.numer /= temp;
    num1.reduce();
    return num1;
}

Fraction operator *(Fraction &num1, Fraction &num2){
    num1.numer *= num2.numer;
    num1.denom *= num2.denom;
    num1.reduce();
    return num1;
}
Fraction operator /(Fraction &num1, Fraction &num2){
    if (num2.numer == 0) {
        cout << "dividing by zero\n";
        exit(1);
    }
    num1.numer *= num2.denom;
    num1.denom *= num2.numer;
    num1.reduce();
    return num1;
}
// fraction.h

#ifndef  FRACTION_H
#define  FRACTION_H

class Fraction {
public:
  void input();
	void display();         // display fraction
	friend Fraction operator +(Fraction &frac1, Fraction &frac2);  
	friend Fraction operator -(Fraction &frac1, Fraction &frac2);  
	friend Fraction operator *(Fraction &frac1, Fraction &frac2);  
	friend Fraction operator /(Fraction &frac1, Fraction &frac2);  

private:
	void reduce();       
  /* reduce the fraction to its simplest form */
	int numer, denom;
};

#endif
