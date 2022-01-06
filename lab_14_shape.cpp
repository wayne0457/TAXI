//include main.cpp, shape.h and shape.cpp

//main.cpp

#include "shape.h"
#include <iostream>
using namespace std;

double output(Rectangle &someshape){
    return someshape.Area();   
}

double output(Circle &someshape){
    return someshape.Area();   
}

int main(){
    char op;
    Rectangle rec;
    Circle cir;

    cin >> op;

    if (op == 'r') {
        rec.input();
        cout << "Rectangle's area is " << output(rec);
        
    } else if (op == 'c') {
        cir.input();
        cout << "Circle's area is " << output(cir);
    }

    return 0;
}

//shape.h

#include <iostream>
using namespace std;

#ifndef shape_h
#define shape_h

class Shape {
public:
    virtual double Area() = 0;
};

class Rectangle : public Shape {
public:
    Rectangle();
    double Area();
    void input();
private:
    double width;
    double length;
};

class Circle : public Shape {
public:
    Circle();
    double Area();
    void input();
private:
    double radius;
};

#endif

//shape.cpp

#include "shape.h"
#include <iostream>

Rectangle::Rectangle(){
    width = 0;
    length = 0;
}

Circle::Circle(){
    radius = 0;
}

void Rectangle::input(){
    cin >> width >> length;
}

void Circle::input(){
    cin >> radius;
}

double Rectangle::Area(){
    return width * length;
}

double Circle::Area(){
    return radius * radius * 3.1416;
}
