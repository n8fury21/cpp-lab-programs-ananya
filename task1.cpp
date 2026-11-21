
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    string name;
    int accountNumber;
    double balance;

    static int count;

public:

    // Constructor
    BankAccount(string n = "Unknown", int acc = 0, double b = 0) {
        name = n;
        accountNumber = acc;
        balance = b;
        count++;
        cout << "Constructor called\n";
    }

    // Copy Constructor
    BankAccount(const BankAccount &obj) {
        name = obj.name;
        accountNumber = obj.accountNumber;
        balance = obj.balance;
        count++;
        cout << "Copy Constructor called\n";
    }

    // Destructor
    ~BankAccount() {
        count--;
        cout << "Destructor called\n";
    }

    // Inline function
    inline void display() {
        cout << "\nName: " << name;
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nBalance: " << balance << endl;
    }

    // Function Overloading
    void deposit(int amount) {
        balance += amount;
    }

    void deposit(double amount) {
        balance += amount;
    }

    // Default Argument
    void showMessage(string msg = "Account Details") {
        cout << "\n" << msg << endl;
    }

    // Static Member Function
    static void showCount() {
        cout << "Active Accounts: " << count << endl;
    }

    // Friend Function
    friend void compare(BankAccount a, BankAccount b);

    // Operator Overloading
    BankAccount operator+(BankAccount obj) {
        return BankAccount("Combined", 999, balance + obj.balance);
    }

    bool operator==(BankAccount obj) {
        return accountNumber == obj.accountNumber;
    }
};

// Initialize static member
int BankAccount::count = 0;

// Friend Function Definition
void compare(BankAccount a, BankAccount b) {
    if (a.balance > b.balance)
        cout << "\nFirst account has more balance";
    else if (b.balance > a.balance)
        cout << "\nSecond account has more balance";
    else
        cout << "\nBoth accounts have equal balance";
}

int main() {

    // Week 1: Strings, References and Pointers
    string studentName = "Ananya";
    string &ref = studentName;
    string *ptr = &studentName;

    cout << "Original Name: " << studentName;
    cout << "\nUsing Reference: " << ref;
    cout << "\nUsing Pointer: " << *ptr << endl;

    // Week 3 and 4: Classes, Objects and Constructors
    BankAccount a("Ananya", 101, 5000);
    BankAccount b("stephen", 102, 3000);

    // Week 2: Inline Function
    a.display();

    // Function Overloading
    a.deposit(500);
    a.deposit(250.50);

    // Default Argument
    a.showMessage();

    // Week 5: Static Member
    BankAccount::showCount();

    // Friend Function
    compare(a, b);

    // Week 6: Operator Overloading (+)
    BankAccount c = a + b;
    c.showMessage("Combined Account");
    c.display();

    // Operator Overloading (==)
    if (a == b)
        cout << "\nSame Account Number";
    else
        cout << "\nDifferent Account Numbers";

    // Copy Constructor
    BankAccount d = a;

    cout << "\n\nCopied Account:";
    d.display();

    return 0;
}
