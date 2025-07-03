#include<iostream>
#include<vector>

using namespace std;

// Not Following LSP

// Abstract class
class Account{
        public:
                virtual void deposit(double amt)=0;
                virtual void withdraw(double amt)=0;
};

class SavingAccount:public Account{
        private:
                double balance;
        public:
                SavingAccount(double initialBalance=0){
                        this->balance = initialBalance;
                }
                void deposit(double amt) override{
                        this->balance += amt;
                        cout<<"Deposit in Saving Account " << amt << " current balance " << this->balance<<endl;
                }
                void withdraw(double amt)override{
                        if(this->balance >= amt){
                                this->balance -= amt;
                                cout<<"Withdraw from  Saving Account " << amt << " current balance " << this->balance<<endl;
                        }
                        else{
                                cout<<"Insufficient Balance in Saving Account"<<endl;
                        }
                }
};
class CurrentAccount:public Account{
        private:
                double balance;
        public:
                CurrentAccount(double initialBalance=0){
                        this->balance = initialBalance;
                }
                void deposit(double amt) override{
                        this->balance += amt;
                        cout<<"Deposit in current Account " << amt << " current balance " << this->balance<<endl;
                }
                void withdraw(double amt)override{
                        if(this->balance >= amt){
                                this->balance -= amt;
                                cout<<"Withdraw from  current Account " << amt << " current balance " << this->balance<<endl;
                        }
                        else{
                                cout<<"Insufficient Balance in current Account"<<endl;
                        }
                }
};

class FixedDepositAccount:public Account{
        private:
                double balance;
        public:
                FixedDepositAccount(double initialBalance=0){
                        this->balance = initialBalance;
                }
                void deposit(double amt) override{
                        this->balance += amt;
                        cout<<"Deposit in Fixed Deposit Account " << amt << " current balance " << this->balance<<endl;
                }
                void withdraw(double amt)override{
                        throw logic_error("Cannot withdraw from Fixed Deposit Account");
                }
};



class BankClient{
        private:
                vector<Account*>accounts;
        public:
                BankClient(vector<Account*>accounts){
                        this->accounts = accounts;
                }
                void processTransactions(){
                        for(auto acc: accounts){
                                acc->deposit(1000);
                                try{
                                        acc->withdraw(500);
                                }
                                catch(logic_error e){
                                        cout<<"Exception caught " << e.what()<<endl;
                                }
                        }
                }

};


int main(){

        vector<Account*>accounts;
        accounts.push_back(new SavingAccount(1000));
        accounts.push_back(new CurrentAccount(1000));
        accounts.push_back(new FixedDepositAccount(1000));

        BankClient* client = new BankClient(accounts);
        client->processTransactions();

        return 0;
}