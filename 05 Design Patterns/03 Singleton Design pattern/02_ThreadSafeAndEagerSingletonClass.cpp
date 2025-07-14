#include<iostream>
#include<mutex>
using namespace std;

// as usual normal class
class Singleton{
        public:
         Singleton(){
                cout << "Singleton is created : Singleton constructor called !!" << endl;
        }
};


// trying to make singleton class
class SingletonClass{
        private:
                static SingletonClass* instance;
                SingletonClass(){
                        cout << "SingletonClass is created : SingletonClass constructor called !!" << endl;
                }
                
        public:
                static SingletonClass* getInstance(){
                        return instance;
                }
};

// initializing static variable/member - eager initilization
SingletonClass* SingletonClass::instance = new SingletonClass();

int main(){

        SingletonClass* s1 = SingletonClass::getInstance();
        SingletonClass* s2 = SingletonClass::getInstance();

        cout << (s1== s2) << endl;

        cout << &(*s1) << endl;
        cout << &(*s2) << endl;

        return 0;
}