#include<iostream>
#include <string>
using namespace std;

class Account{
        private:
                double balance;
                string accountHolder;
        public:
                Account(double balance,string accountHolder){
                        this->balance = balance;
                        this->accountHolder = accountHolder;
                }

                // getter and setter
                int getAccount(){
                        return this->balance;
                }
                string getAccountHolder(){
                        return this->accountHolder;
                }

                void depositAmount(double amount){

                        // validation
                        if(amount > 0){
                                this->balance += amount;
                                cout <<"Amount Deposited Successfully" << "(+"<<amount<<")" << " New Balance is " << this->balance << endl;
                        }else{
                                cout << "Invalid amount to deposit" << endl;
                        }
                }

                void withdrawAmount(double amount){

                        // validation
                        if(amount > 0 && amount <= this->balance){
                                this->balance -= amount;
                                cout << "Amount Withdrawn Successfully" << "(-"<<amount<<")" << " New Balance is " << this->balance << endl;
                        }else{
                                cout << "Invalid amount to withdraw" << endl;
                        }
                }
};

int  main(){

        Account* manishAccount = new Account(1000,"Manish");

        cout << "Balance is " << manishAccount->getAccount() << endl;
        cout << "Holder Name is " << manishAccount->getAccountHolder() << endl;

        manishAccount->depositAmount(2000);
        manishAccount->withdrawAmount(500);
        manishAccount->withdrawAmount(5000);

        delete manishAccount;

        
        return 0;
}