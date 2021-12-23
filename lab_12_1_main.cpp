//main
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
        add(&ans, &num2); break;
      case '-':
        sub(&ans, &num2); break;
      case '*':
        mul(&ans, &num2); break;
      case '/':
        div(&ans, &num2); break;
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
