#include<iostream>
#include<string>
using namespace std;

class CompanyPolicy{
        public:
        void showPolicy(){
                cout << "General company policy applies." << endl;
        }
};

class HR: public CompanyPolicy{
        public:
        void doHRStuff(){
                cout << "HR stuff" << endl;
        }
};
class Finance: public CompanyPolicy{
        public:
        void doFinanceStuff(){
                cout << "Finance stuff" << endl;
        }
};

class Employee: public HR, public Finance{
        public:
        void doEmployeeStuff(){
                cout << "Employee stuff" << endl;
        }
};

int main(){

        Employee* emp;

        // emp->showPolicy();
        // ambiguity

        emp->doEmployeeStuff();

        return 0;
}