#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() { // virtual function - not pure virtual - so need to override - not must
        cout << "Area of shape" << endl;
    }
};

class Circle : public Shape {
public:
    void area() override {
        cout << "Area of circle: πr^2" << endl;
    }
};

class Rectangle : public Shape {
public:
    void area() override {//virtual function - not pure virtual - so need to override - not must
        cout << "Area of rectangle: length × width" << endl;
    }
};

int main() {
    Shape* s1 = new Circle();
    Shape* s2 = new Rectangle();

    s1->area(); // Output: Area of circle: πr^2
    s2->area(); // Output: Area of rectangle: length × width

    delete s1;
    delete s2;
    return 0;
}