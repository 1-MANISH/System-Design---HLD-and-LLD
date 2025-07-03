#include<iostream>

using namespace std;

// strengthen
// Class Invariant of a parent class Object should not be broken by child class Object.
// Hence child class can either maintain or strengthen the invariant but never narrows it down.

//Invariant : Balance cannot be negative
class BankAccount {
protected:
    double balance;
public:
    BankAccount(double b) {
        if (b < 0) throw invalid_argument("Balance can't be negative"); // logic_error
        balance = b;
    }
    virtual void withdraw(double amount) {
        if (balance - amount < 0) throw runtime_error("Insufficient funds");
        balance -= amount;
        cout<< "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};

//Brakes invariant : Should not be allowed.
class CheatAccount : public BankAccount {
public:
    CheatAccount(double b) : BankAccount(b) {}

    void withdraw(double amount) override {
        balance -= amount; // LSP break! Negative balance allowed
        cout<< "Amount withdrawn. Remaining balance is " << balance << endl;
    }
};

int main() {
    BankAccount* bankAccount = new BankAccount(100);
    bankAccount->withdraw(200);

    CheatAccount* cheatAccount = new CheatAccount(100);
    cheatAccount->withdraw(200);
}
    