#include<iostream>
#include<vector>
using namespace std;

class Product{
        public:
        string name;
        double price;

        Product(string name, double price){
                this->name = name;
                this->price = price;
        }
};

// Violated SRP : ShoppingCart class handling multiple responsibilities

class ShoppingCart{
        private:
        vector<Product*>cartProducts;

        public:
        void addProduct(Product*product){
                cartProducts.push_back(product);
        }

        const vector<Product*> getCartProducts(){
                return cartProducts;
        }

        // 1. calculate total price
        double calculateTotalPrice(){
                double totalPrice = 0;
                for(auto product:cartProducts){
                        totalPrice += product->price;
                }
                return totalPrice;
        }

        //2. SRP violated : Print Cart Invoice (should be in another class)
        void printCartInvoice(){
                cout<<"Cart Invoice"<<endl;
                for(auto product:cartProducts){
                        cout<<"Product: "<<product->name<<" Price: "<<product->price<<endl;
                }
                cout<<"Total Price: "<<calculateTotalPrice()<<endl;
        }

        // 3. SRP Violated - Saves to DB (should be in another class)
        void saveToDB(){
                // save to DB
                cout << "Saving shopping cart to database..." << endl;
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

        cout <<"Cart Total Price: " << cart->calculateTotalPrice() << endl;
        cart->printCartInvoice();
        cart->saveToDB();


        return 0;
}