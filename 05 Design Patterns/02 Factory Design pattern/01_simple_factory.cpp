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

class BurgerFactory{
        public:

        //static means that this method belongs to the class itself, not to any object instance.
                static Burger* createBurger(string type){
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

int main(){

        Burger* basicBurger = BurgerFactory::createBurger("basic");
        basicBurger->prepareBurger();
        

        BurgerFactory* bf = new BurgerFactory();
        Burger* burger = bf->createBurger("standard");
        burger->prepareBurger();

        delete basicBurger;
        delete burger;
        delete bf;

        return 0;
}