#include<iostream>
#include<string>
using namespace std;

class Calculator{
        public:
        int add(int a,int b){
                return a+b;
        }
        int add(int a,int b,int c){
                return a+b+c;
        }

        string add(string a,string b){
                return a+b;
        }
};

int main(){

        Calculator* calculator = new Calculator();
        cout<<calculator->add(2,3)<<endl;
        cout<<calculator->add(2,3,4)<<endl;
        cout<<calculator->add("Hello ","World")<<endl;

        
        return 0 ;
}