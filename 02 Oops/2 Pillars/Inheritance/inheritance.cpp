#include<iostream>
#include<string>

using namespace std;


class Car{

        protected:// only accessible by derived classes
                string brand;
                string modal;
                bool isEngineOn;
                int currentSpeed;
        public:

                Car(string b, string m){
                        cout << "Parent Constructor" << endl;
                        this->brand = b;
                        this->modal = m;
                        isEngineOn = false;
                        currentSpeed = 0;
                }

                void startEngine(){
                        isEngineOn = true;
                        cout << brand << " " << modal << " : Engine starts with a roar!" << endl;
                }

                void stopEngine(){
                        isEngineOn = false;
                        currentSpeed = 0;
                        cout << brand << " " << modal << " : Engine turned off." << endl;
                }

                void accelerate(){
                        if (!isEngineOn){
                                cout << brand << " " << modal << " : Engine is off! Cannot accelerate." << endl;
                                return;
                        }
                        currentSpeed += 20;
                        cout << brand << " " << modal << " : Accelerating to " << currentSpeed << " km/h" << endl;
                }
                
                void brake(){
                        currentSpeed -= 20;
                        if (currentSpeed < 0) currentSpeed = 0;
                        cout << brand << " " << modal << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
                }

};

class ManualCar:public Car{
        private:
                int currentGear;
        
        public:
                ManualCar(string b, string m):Car(b,m){
                        cout << "ManualCar Constructor" << endl;
                        currentGear = 0;
                }
                void shiftGear(int gear){
                        if (!isEngineOn){
                                cout << brand << " " << modal << " : Engine is off! Cannot Shift Gear." << endl;
                                return;
                        }
                        currentGear = gear;
                        cout << brand << " " << modal << " : Shifted to gear " << currentGear << endl;
                }
};

class ElectricCar:public Car{
        private:
                int batteryCapacity;
        public:
                ElectricCar(string brand,string model):Car(brand,model){
                        cout << "ElectricCar Constructor" << endl;
                        this->batteryCapacity = 100;
                }

                void chargeBattery(int capacity){
                        this->batteryCapacity = capacity;
                        cout << brand << " " << modal << " : Battery charged to " << batteryCapacity << " %" << endl;
                }
        
};

int  main(){

        ManualCar* mcar = new ManualCar("Honda","Civic");
        ElectricCar* ecar = new  ElectricCar("Tesla","Model 3");

        mcar->startEngine();
        mcar->shiftGear(2);
        mcar->accelerate();
        mcar->accelerate();
        mcar->brake();
        mcar->stopEngine();

        ecar->startEngine();
        ecar->accelerate();
        ecar->accelerate();
        ecar->chargeBattery(80);
        ecar->brake();
        ecar->stopEngine();

        delete mcar;
        delete ecar;

        return 0;
}