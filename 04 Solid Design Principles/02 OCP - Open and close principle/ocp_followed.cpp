#include<iostream>
#include<vector>

using namespace std;

class Product{
        public:
        string  name;
        double price;

        Product(string name,double price){
                this->name = name;
                this->price = price;
        }
};

class ShoppingCart{

        private:
        vector<Product*>cartProducts;

        public:
        void addProduct(Product* p){
                cartProducts.push_back(p);
        }
        const vector<Product*> getCartProducts(){
                return cartProducts;
        }

        double calculateCartTotalPrice(){
                double totalPrice = 0;
                for(auto p:cartProducts){
                        totalPrice += p->price;
                }
                return totalPrice;
        }
};

class CartInvoicePrinter{
        private:
                ShoppingCart* cart;
        public:
                CartInvoicePrinter(ShoppingCart* cart){
                        this->cart = cart;
                }

                void printCartInvoice(){
                        cout << "Cart Invoice" << endl;
                        for(auto p:cart->getCartProducts()){
                                cout << "Product: " << p->name << " Price: " << p->price << endl;
                        }
                        cout << "Total Price: " << cart->calculateCartTotalPrice() << endl;
                }
};

// Abstract class
class DBPersistence{
        private:
                ShoppingCart* cart;
        public:
                virtual void saveToDB(ShoppingCart* cart)=0; // pure virtual function
};

class SqlDBPersistence:public DBPersistence{
        public:
                void saveToDB(ShoppingCart* cart) override{
                        // save to SQL DB
                        cout << "Saving shopping cart to sql database..." << endl;
                }
};
class MongoDBPersistence:public DBPersistence{
        public:
                void saveToDB(ShoppingCart* cart) override{
                        // save to mongo DB
                        cout << "Saving shopping cart to mongo database..." << endl;
                }
};
class FileDBPersistence:public DBPersistence{
        public:
                void saveToDB(ShoppingCart* cart) override{
                        // save to file DB
                        cout << "Saving shopping cart to file database..." << endl;
                }
};

int main(){

        Product* p1 = new Product("Macbook", 100000);
        Product* p2 = new Product("Iphone", 50000);
        Product* p3 = new Product("Apple Watch", 30000);

        ShoppingCart* cart = new ShoppingCart();
        cart->addProduct(p1);
        cart->addProduct(p2);
        cart->addProduct(p3);

        CartInvoicePrinter* printer = new CartInvoicePrinter(cart);
        printer->printCartInvoice();

        SqlDBPersistence* sql =new SqlDBPersistence(); 
        MongoDBPersistence* mongo =new MongoDBPersistence(); 
        FileDBPersistence* file =new FileDBPersistence(); 
        
        sql->saveToDB(cart);
        mongo->saveToDB(cart);
        file->saveToDB(cart);

        return 0;
}