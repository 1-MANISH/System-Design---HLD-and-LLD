#include<iostream>
using namespace std;

// Analogy - A Car is a type of Vehicle.
class Vehicle{
        public:
        void move(){
                cout<<"Vehicle is moving"<<endl;
        }
};

class Car:public Vehicle{
        public:
        void honk(){
                cout<<"Car horn"<<endl;
        }

};

int main(){

        Car* c1;
        c1->move();
        c1->honk();

        delete c1;

        return 0;
}