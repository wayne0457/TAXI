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

void add(Fraction *num1, Fraction *num2){
    int temp = num1 -> denom;
    num1 -> numer *= num2 -> denom;
    num1 -> denom *= num2 -> denom;
    num2 -> numer *= temp;
    num1 -> numer += num2 -> numer;
    num2 -> numer /= temp;
    num1 -> reduce();
}

void sub(Fraction *num1, Fraction *num2){
    int temp = num1 -> denom;
    num1 -> numer *= num2 -> denom;
    num1 -> denom *= num2 -> denom;
    num2 -> numer *= temp;
    num1 -> numer -= num2 -> numer;
    num2 -> numer /= temp;
    num1 -> reduce();
}

void mul(Fraction *num1, Fraction *num2){
    num1 -> numer *= num2 -> numer;
    num1 -> denom *= num2 -> denom;
    num1 -> reduce();
}
void div(Fraction *num1, Fraction *num2){
    if (num2 -> numer == 0) {
        cout << "dividing by zero\n";
        exit(1);
    }
    num1 -> numer *= num2 -> denom;
    num1 -> denom *= num2 -> numer;
    num1 -> reduce();
}
