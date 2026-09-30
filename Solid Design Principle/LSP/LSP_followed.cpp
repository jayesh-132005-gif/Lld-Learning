#include <iostream>
#include <vector>
#include <stdexcept>
#include <typeinfo>

using namespace std;

class DepositOnlyAccount {
    public:
        virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepositOnlyAccount {
    public: 
        virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public WithdrawableAccount {
    private:
        double balance;
    public:
        SavingsAccount() { 
            balance = 0; 
        }
        void deposit(double amount) {
            balance += amount;
            cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
        }
        void withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
            } else {
                cout << "Insufficient funds in Savings Account!\n";
            }
        }
};

class CurrentAccount : public WithdrawableAccount {
    private:
        double balance;
    
    public:
        CurrentAccount() { 
            balance = 0; 
        }
    
        void deposit(double amount) {
            balance += amount;
            cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
        }
    
        void withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
            } else {
                cout << "Insufficient funds in Current Account!\n";
            }
        }
};

class FixedTermAccount : public DepositOnlyAccount {
    private:
        double balance;

    public:
    FixedTermAccount() {
        balance = 0;
    }   
    
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }
};

class BankClient {






    
};



int main () {







    return 0;
}


