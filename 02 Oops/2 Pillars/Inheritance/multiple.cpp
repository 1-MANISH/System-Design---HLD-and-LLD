#include<iostream>
using namespace std;

// Analogy - a smart phone is both phone and camera.

class Camera{
        public:
        void takePicture(){
                cout<<"Taking Picture"<<endl;
        }
};

class Phone {
        public:
        void makeCall(){
                cout<<"Making Call"<<endl;
        }
};

class SmartPhone:public Camera,public Phone{
};


int main(){

        SmartPhone smp;

        smp.takePicture();
        smp.makeCall();

        delete &smp;

        return 0;
}