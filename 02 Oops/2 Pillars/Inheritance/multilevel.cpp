#include<iostream>
using namespace std;

// Analogy - A Sports Car is a type of Car. and Car is a type of Vehicle.

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
class SportCar:public Car{
        public:
        void turboBoost(){
                cout<<"Turbo Boost Activated"<<endl;
        }
};


int main(){

        SportCar smp;
        smp.move();
        smp.honk();
        smp.turboBoost();

        delete &smp;

        return 0;
}