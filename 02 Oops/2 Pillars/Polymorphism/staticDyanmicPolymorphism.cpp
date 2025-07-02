#include<iostream>
#include<string>

using namespace std;

class Car{
        protected:
                string brand ,model;
                int currentSpeed;
                bool isEngineOn;

        public:
                Car(string brand,string model){
                        this->brand = brand;
                        this->model = model;
                        this->currentSpeed = 0;
                        this->isEngineOn = false;
                }

                void startEngine(){
                        if(!isEngineOn){
                                isEngineOn = true;
                                cout << brand << " " << model << " : Engine starts with a roar!" << endl;
                        }else{
                                cout << brand << " " << model << " : Engine is already on." << endl;
                        }
                }

                void stopEngine(){
                        if(isEngineOn){
                                isEngineOn = false;
                                currentSpeed = 0;
                                cout << brand << " " << model << " : Engine turned off." << endl;
                        }else{
                                cout << brand << " " << model << " : Engine is already off." << endl;
                        }
                }


                // to demonstrate pure virtual function
                // and inside derived classes we need to override

                // combo of static(method overloading)
                // and dynamic (method overring)
                // we want to implement

                // pure virtual function - need to be overridden
                virtual void accelerate() = 0; //  Abstract method for Dynamic Polymorphism
                virtual void accelerate(int speed) = 0; // Abstract method for Static Polymorphism
                virtual void brake() = 0; // Abstract method for dynamic polymorphism

                virtual ~Car(){}
};

// on acc -> +20
// on brake -> -20
// gearShift -> -2      

class ManualCar:public Car{
        private:
                int currentGear;
        public:
                ManualCar(string brand,string model) : Car(brand,model){
                        this->currentGear = 0;
                }

                // specialized method
                void shiftGear(int gear){
                        if(!isEngineOn){
                                cout << brand << " " << model << " : Engine is off! Cannot Shift Gear." << endl;
                                return;
                        }
                        currentGear = gear;
                        currentSpeed-=2;
                        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
                }

                // overriding - dynamic polymorphism
                void accelerate()override{
                        if(!isEngineOn){
                                cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
                                return;
                        }
                        currentSpeed+=20;
                        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
                }

                // overloading+overriding at same time
                void accelerate(int speed)override{
                        if(!isEngineOn){
                                cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
                                return;
                        }
                        currentSpeed+=speed;
                        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
                }

                // overriding
                void brake()override{
                        currentSpeed -= 20;
                        if (currentSpeed < 0) currentSpeed = 0;
                        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
                }

};


// on acc -> +25
// on brake -> -10

class ElectricCar:public Car{
        private:
                int batteryCapacity;
        public:
                ElectricCar(string brand,string model) : Car(brand,model){
                        this->batteryCapacity = 100;
                }

                // specialized method
                void chargeBattery(int capacity){
                        this->batteryCapacity = capacity;
                        cout << brand << " " << model << " : Battery charged to " << batteryCapacity << " %" << endl;
                }

                // overriding - dynamic polymorphism
                void accelerate()override{
                        if(!isEngineOn){
                                cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
                                return;
                        }
                        currentSpeed+=25;
                        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
                }

                // overloading+overriding at same time
                void accelerate(int speed)override{
                        if(!isEngineOn){
                                cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
                                return;
                        }
                        currentSpeed+=speed;
                        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
                }

                // overriding
                void brake()override{
                        currentSpeed -= 10;
                        if (currentSpeed < 0) currentSpeed = 0;
                        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
                }
};

int main(){

        Car* mCar  = new ManualCar("Honda","Civic");
        Car* eCar = new  ElectricCar("Tesla","Model 3");

        mCar->startEngine();
        // mCar->shiftGear(2); as we used override so this will not work
        static_cast<ManualCar*>(mCar)->shiftGear(2);
        mCar->accelerate();
        mCar->accelerate();
        mCar->brake();
        mCar->accelerate();
        mCar->stopEngine();

        cout << "----------------------" << endl;

        eCar->startEngine();
        eCar->accelerate();
        eCar->accelerate();
        // eCar->chargeBattery(80);
        static_cast<ElectricCar*>(eCar)->chargeBattery(80);
        eCar->brake();
        mCar->accelerate();
        eCar->stopEngine();

        delete mCar;
        delete eCar;

        return 0;
}
