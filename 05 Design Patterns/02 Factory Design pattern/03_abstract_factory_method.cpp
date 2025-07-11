#include<iostream>
using namespace std;


// Burgers
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

// Garlic Bread

class GarlicBread{
        public:
                virtual void prepareBread() = 0;
};

class BasicBread:public GarlicBread{
        public:
                void prepareBread() override{
                        cout<<"Preparing basic bread with garlic"<<endl;
                }
};
class StandardBread:public GarlicBread{
        public:
                void prepareBread() override{
                        cout<<"Preparing standard bread with garlic , cheese"<<endl;
                }
};

class PremiumBread:public GarlicBread{
        public:
                void prepareBread() override{
                        cout<<"Preparing premium bread with garlic , cheese , mayo"<<endl;
                }
};

class BasicWheatBread:public GarlicBread{
        public:
                void prepareBread() override{
                        cout<<"Preparing basic *wheat* bread with garlic"<<endl;
                }
};
class StandardWheatBread:public GarlicBread{
        public:
                void prepareBread() override{
                        cout<<"Preparing standard *wheat* bread with garlic , cheese"<<endl;
                }
};

class PremiumWheatBread:public GarlicBread{
        public:
                void prepareBread() override{
                        cout<<"Preparing premium *wheat* bread with garlic , cheese , mayo"<<endl;
                }
};

// Factory

class Factory{
        public:         
                virtual  Burger* createBurger(string& type)= 0;
                virtual  GarlicBread* createBread(string& type)= 0;
};

class Singh:public Factory{
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
                GarlicBread* createBread (string& type) override {
                        if(type == "basic")
                                return new BasicBread();
                        else if(type == "standard")
                                return new StandardBread();
                        else if(type == "premium")
                                return new PremiumBread();
                        else
                                return nullptr;
                }
};

class King:public Factory{
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
                GarlicBread* createBread (string& type) override {
                        if(type == "basic")
                                return new BasicWheatBread();
                        else if(type == "standard")
                                return new StandardWheatBread();
                        else if(type == "premium")
                                return new PremiumWheatBread();
                        else
                                return nullptr;
                }
};

int main(){

        string type = "premium";
        Factory* f = new King();
        Burger* burger = f->createBurger(type);
        burger->prepareBurger();
        GarlicBread* bread = f->createBread(type);
        bread->prepareBread();


        delete burger;
        delete bread;
        delete f;
        

        return 0;
}