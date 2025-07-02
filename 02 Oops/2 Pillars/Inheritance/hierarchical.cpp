#include<iostream>
using namespace std;

// Analogy - So the Dog and cat both are animal

class Animal{
        public:
        void eat(){
                cout<<"Animal is Eating"<<endl;
        }
};

class Dog:public Animal{
        public:
        void bark(){
                cout<<"Dog is Barking"<<endl;
        }
};

class Cat:public Animal{
        public:
        void meow(){
                cout<<"Cat is Meowing"<<endl;
        }
};



int main(){

        Dog d;
        d.eat();
        d.bark();

        Cat c;
        c.eat();
        c.meow();

        delete &d;
        delete &c;


        return 0;
}