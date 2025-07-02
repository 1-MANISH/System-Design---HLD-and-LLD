#include<iostream>
#include<string>
using namespace std;

class CompanyPolicy{
        public:
        void showPolicy(){
                cout << "General company policy applies." << endl;
        }
};

// HR inherits virtually from CompanyPolicy
class HR: virtual public CompanyPolicy{
        public:
        void doHRStuff(){
                cout << "HR stuff" << endl;
        }
};

// Finance inherits virtually from CompanyPolicy
class Finance:virtual public CompanyPolicy{
        public:
        void doFinanceStuff(){
                cout << "Finance stuff" << endl;
        }
};

// Employee inherits from both HR and Finance
class Employee: public HR, public Finance{
        public:
        void doEmployeeStuff(){
                cout << "Employee stuff" << endl;
        }
};

int main(){

        cout <<23 <<endl;

        Employee* emp = new Employee();

        emp->showPolicy(); 
        emp->doEmployeeStuff();

        

        return 0;
}