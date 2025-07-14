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
                static mutex mtx;
                SingletonClass(){
                        cout << "SingletonClass is created : SingletonClass constructor called !!" << endl;
                }
                
        public:
                static SingletonClass* getInstance(){
                        if(instance == nullptr){ // to avoid putting lock again and again
                                lock_guard<mutex> lock(mtx) ; //local for thread safety
                                if(instance == nullptr){// double locking check
                                         instance = new SingletonClass();
                                }
                        }
                        return instance;
                }
};

SingletonClass* SingletonClass::instance = nullptr;
mutex SingletonClass::mtx;

int main(){

        SingletonClass* s1 = SingletonClass::getInstance();
        SingletonClass* s2 = SingletonClass::getInstance();

        cout << (s1== s2) << endl;

        cout << &(*s1) << endl;
        cout << &(*s2) << endl;

        return 0;
}