#include<iostream>
using namespace std;


// Strategy design pattern


// Strategy Interface(Abstraction in c++) for Robot Walk
class Walkable{
        public:
                virtual void walk() = 0;
                virtual ~Walkable(){}
};

// Concreate Strategy for Robot Walk
class NormalWalk:public Walkable{
        public:
                void walk() override{
                        cout<<"Robot walking normally"<<endl;
                }
};
class NoWalk:public Walkable{
        public:
                void walk() override{
                        cout<<"Robot  can't walk "<<endl;
                }
};


// Strategy Interface for Robot Talk
class Talkable{
        public:
                virtual void talk() = 0;
                virtual ~Talkable(){}
};

// Concreate Strategy for Robot Talk
class NormalTalk:public Talkable{
        public:
                void talk() override {
                        cout<<"Robot talking normally"<<endl;
                }
};
class NoTalk:public Talkable{
        public:
                void talk() override {
                        cout<<"Robot can't talk "<<endl;
                }
};

// Strategy Interface for Robot Fly
class Flyable{
        public:
                virtual void fly()=0;
                virtual ~Flyable(){}
};

// concrete Strategy for Robot Fly
class NormalFly:public Flyable{
        public:
                void fly() override{
                        cout<<"Robot flying normally"<<endl;
                }
};
class NoFly:public Flyable{
        public:
                void fly() override{
                        cout<<"Robot can't fly "<<endl;
                }
};

// if we have to add some more flying roles
class WingFly:public Flyable{
        public:
                void fly() override{
                        cout<<"Robot flying with wings"<<endl;
                }
};
class JetFly:public Flyable{
        public:
                void fly() override {
                        cout<<"Robot flying with jet"<<endl;
                }
};

// Main Robot class-Client - Base class

class Robot{
        public:
                Talkable* t;
                Walkable* w;
                Flyable* f;

                Robot(Talkable* t,Walkable* w,Flyable* f){
                        this->t=t;
                        this->w=w;
                        this->f=f;
                }

                // delegate of strategy
                void talk(){
                        t->talk();
                }
                void walk(){
                        w->walk();
                }
                void fly(){
                        f->fly();
                }

                virtual void projection()=0;
};

class CompanionRobot:public Robot{
        public:
                CompanionRobot(Talkable* t,Walkable* w,Flyable* f):Robot(t,w,f){}

                void projection() override {
                        cout<<"Companion Robot projection"<<endl;
                }
};

class SparrowRobot:public Robot{
        public:
                SparrowRobot(Talkable* t,Walkable* w,Flyable* f):Robot(t,w,f){}

                void projection() override {
                        cout<<"Sparrow Robot projection"<<endl;
                }
};



int main(){

        Robot* companionRobot = new CompanionRobot(
                new NormalTalk(),
                new NormalWalk(),
                new NoFly()
        );

        companionRobot->talk();
        companionRobot->walk();
        companionRobot->fly();
        companionRobot->projection();

        cout << "-----------------------------" <<endl;

        Robot* sparrowRobot = new SparrowRobot(
                new NoTalk(),
                new NoWalk(),
                new WingFly()
        );

        sparrowRobot->talk();
        sparrowRobot->walk();
        sparrowRobot->fly();
        sparrowRobot->projection();

        delete companionRobot;

        return 0;
}