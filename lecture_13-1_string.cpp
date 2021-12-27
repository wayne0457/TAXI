#include <iostream>
#include <string>
using namespace std;

int main(){
    string str = ("Test string");
    for (string::iterator it = str.begin(); it != str.end(); ++it) {
        cout << *it;
    }
    cout << endl;
    
    for (int i = 0; i < str.length(); ++i) {
        cout << str.at(i);
    }
    cout << endl;

    for (int i = 0; i < str.length(); ++i) {
        cout << str[i];
    }
    cout << endl;

    return 0;
}
