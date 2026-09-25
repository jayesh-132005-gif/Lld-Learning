#include <iostream>
#include <vector>
#include <stdexcept>  
using namespace std;

class Account {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account {
private:
    double balance;

public:
    SavingAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Savings Account. New Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in Savings Account!\n";
        }
    }
};

class CurrentAccount : public Account {
private:
    double balance;

public:
    CurrentAccount()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from Current Account. New Balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in Current Account!\n";
        }
    }
};

class FixedAccountTerm : public Account {
private:
    double balance;

public:
    FixedAccountTerm()
    {
        balance = 0;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in Fixed Term Account. New Balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        throw logic_error("Withdrawal not allowed in Fixed Term Account!");
    }
};

class BankClient {
private:
    vector<Account *> accounts;

public:
    BankClient(vector<Account *> accounts) {
        this->accounts = accounts;
    }

    void processTransactions() {
        for (Account* acc : accounts) {
            //All accounts allow deposits
            acc->deposit(1000); 

            //Assuming all accounts support withdrawal (LSP Violation)
            try {
                acc->withdraw(500);
            } catch (const logic_error& e) {
                cout << "Exception: " << e.what() << endl;
            }
        }
    }
};

int main() {
 
    // Make a list of accounts of customer.
    vector<Account*> accounts;

    // Create a three accounts of different types
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedAccountTerm());

    // Give accounts to customer / Bankclient
    BankClient* client = new BankClient(accounts);
    
    //  Process transactions for all accounts
    client->processTransactions();

    return 0;
}