#include<iostream>
using namespace std;

class Burger{
        public:
                virtual void prepareBurger() = 0; // pure virtual
                virtual ~Burger(){} // virtual destructor
};


class BasicBurger:public Burger{
        public:
                void prepareBurger() override{
                        cout<<"Preparing basic burger with bun , patty , and ketchup"<<endl;
                }
};

class StandardBurger:public Burger{
        public:
                void prepareBurger() override{
                        cout<<"Preparing standard burger with bun , patty , and ketchup + lattuce!"<<endl;
                }
};

class PremiumBurger:public Burger{
        public:
                void prepareBurger() override{
                        cout<<"Preparing premium burger with bun , patty , and ketchup + lattuce! + cheese + mayo"<<endl;
                }
};
class BasicWheatBurger:public Burger{
        public:
                void prepareBurger() override{
                        cout<<"Preparing basic *wheat* burger with bun , patty , and ketchup"<<endl;
                }
};

class StandardWheatBurger:public Burger{
        public:
                void prepareBurger() override{
                        cout<<"Preparing standard *wheat* burger with bun , patty , and ketchup + lattuce!"<<endl;
                }
};

class PremiumWheatBurger:public Burger{
        public:
                void prepareBurger() override{
                        cout<<"Preparing premium *wheat* burger with bun , patty , and ketchup + lattuce! + cheese + mayo"<<endl;
                }
};

class BurgerFactory{
        public:         
                virtual  Burger* createBurger(string& type)= 0;
};

class SinghBurger:public BurgerFactory{
        public:
                Burger* createBurger (string& type)override {
                        if(type == "basic")
                                return new BasicBurger();
                        else if(type == "standard")
                                return new StandardBurger();
                        else if(type == "premium")
                                return new PremiumBurger();
                        else
                                return nullptr;
                }
};

class KingBurger:public BurgerFactory{
        public:
                Burger* createBurger (string& type) override {
                        if(type == "basic")
                                return new BasicWheatBurger();
                        else if(type == "standard")
                                return new StandardWheatBurger();
                        else if(type == "premium")
                                return new PremiumWheatBurger();
                        else
                                return nullptr;
                }
};

int main(){

        string type = "standard";

        BurgerFactory* bs = new SinghBurger();
        Burger* bburger = bs->createBurger(type);
        bburger->prepareBurger();

        BurgerFactory* bk = new KingBurger();
        Burger* kburger = bk->createBurger(type);
        kburger->prepareBurger();

        

        return 0;
}