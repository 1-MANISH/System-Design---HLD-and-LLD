#include<iostream>
#include<string>
using namespace std;

class Complex{
        int real,imag;
        public:
                Complex(int r = 0,int i = 0){
                        this->real = r;
                        this->imag = i;
                }

                Complex operator + (const Complex &obj){
                        Complex temp ;
                        temp.real = this->real+obj.real;
                        temp.imag = this->imag+obj.imag;
                        return temp;
                }

                void display(){
                        cout << real << " + i" << imag << endl;
                }
};

int main(){

        Complex c1 (2,3);
        Complex c2 (4,5);
        c1.display();
        c2.display();

        // we want that
        // Complex* c3 = new Complex(2,3) + new Complex(4,5)
        // so we can do it by operator overloading
        Complex c3 =c1 + c2;
        c3.display();
        
        return 0 ;
}