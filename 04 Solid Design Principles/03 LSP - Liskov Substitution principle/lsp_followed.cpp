#include<iostream>
#include<vector>

using namespace std;

//  Following LSP - in correct way

// Abstract class
class DepositOnlyAccount{
        public:
                virtual void deposit(double amt)=0;
};
class WithdrawableAccount:public DepositOnlyAccount{
        public:
         virtual void withdraw(double amt)=0;
};

class SavingAccount:public WithdrawableAccount{
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
class CurrentAccount:public WithdrawableAccount{
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

class FixedDepositAccount:public DepositOnlyAccount{
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
                
};

// Now Client it tightly coupled

class BankClient{
        private:
                vector<DepositOnlyAccount*>depositsOnlyAccounts;
                vector<WithdrawableAccount*>withdrawableAccounts;
        public:
                BankClient(vector<DepositOnlyAccount*>depositsOnlyAccounts , vector<WithdrawableAccount*>withdrawableAccounts){
                        this->depositsOnlyAccounts = depositsOnlyAccounts;
                        this->withdrawableAccounts = withdrawableAccounts;
                }
                void processTransactions(){
                        for(auto depositOnlyAccount: depositsOnlyAccounts){
                                depositOnlyAccount->deposit(1000);
                        }
                        for(auto withdrawableAccount: withdrawableAccounts){
                                withdrawableAccount->deposit(1000);
                                try{
                                        withdrawableAccount->withdraw(500);
                                }
                                catch(exception& e){
                                        cout<<e.what()<<endl;
                                }
                        }
                }
};


int main(){

        vector<WithdrawableAccount*>withdrawableAccounts;
        vector<DepositOnlyAccount*>depositsOnlyAccounts;

        withdrawableAccounts.push_back(new SavingAccount(1000));
        withdrawableAccounts.push_back(new CurrentAccount(1000));
        depositsOnlyAccounts.push_back(new FixedDepositAccount(1000));

        BankClient* client = new BankClient(depositsOnlyAccounts , withdrawableAccounts);
        client->processTransactions();

        return 0;
}