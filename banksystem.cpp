#include <iostream>
#include<string>

using namespace std;
class Validation {
public:
    static bool nameValidation(string name) {

        string unvalidChar = "/`~!@#$%^&()+-=<>?,{}[]0123456789_";
        for (int i = 0; i < name.size(); i++) {
            if (name.size() < 5 || name.size() > 20 || unvalidChar.find(name[i] >= 0 && unvalidChar.find(name[i]) <= unvalidChar.size())) {
                return false;
            }
            return true;
        }
    }
    static bool passValidation(string pass) {
        for (int i = 0; i < pass.size(); i++) {
            if (pass[i] == ' ' || pass.size() < 8 || pass.size() > 20) {
                return false;
            }
            return true;

        }


    }

    static bool validBalance(double balance) {
        if (balance < 1500) {
            return false;
        }
        return true;
    }

    static bool validSalary(double salary) {
        if (salary < 5000) {
            return false;
        }
        return true;
    }
};

class Person {
protected:
    int id;
    string name, password;
public:
    Person() {}
    Person(int id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    }
    void set_id(int id) {
        this->id = id;
    }
    void set_name(string name) {
        if (Validation::nameValidation(name)) {
            this->name = name;
        }
    }
    void set_password(string password) {
        if (Validation::passValidation(password)) {
            this->password = password;
        }
    }
    int get_id() {
        return id;
    }
    string get_name() {
        return name;
    }
    string get_password() {
        return password;
    }
    void print() {
        cout << "**********************************" << endl;
        cout << "\tthe id is :" << id << endl;
        cout << "\tthe name is :" << name << endl;
        cout << "\tthe password is :" << password << endl;
    }
};

class Client :public Person {
private:
    double balance;
public:
    Client(int id, string name, string password, double balance) :Person(id, name, password) {
        this->balance = balance;
    }
    void set_balance(double balance) {
        if (Validation::validBalance(balance)) {
            this->balance = balance;
        }
    }
    double get_balance() {
        return balance;
    }
    void deposit() {
        double depo = 0;
        cout << "Enter Deposit amount =  $ ";
        cin >> depo;
        balance = depo + balance;
        cout << "your Deposit of balance =  $ " << balance << endl;
    }
    void withdrow();
    void print() {
        Person::print();
        cout << "\t your balance is  =  $ " << balance << endl << endl;
        cout << "********************************************" << endl;
    }
    void transferto(double amount, Client& acc2) {
        if (amount > balance) {
            cout << "your balance is not enough";
        }
        else {
            balance -= amount;
            acc2.balance += amount;
        }
    }
    void chackbalance() {
        cout << "your balance is :- $ " << balance << endl;
    }
};

void Client::withdrow() {
    double withdrow = 0;
    cout << "Enter your withdrow = $ ";
    cin >> withdrow;
    if (balance > withdrow) {
        balance = balance - withdrow;
        cout << "After withdrow your balance is = $ " << balance << endl;
    }
    else {
        cout << "your balance not Enough\n";
    }
}

class Employee : public Person {
private:
    double salary;
public:
    Employee() :Person() {


    }
    Employee(int id, string name, string password, double salary) :Person(id, name, password) {
        this->salary = salary;
    }
    void set_salary(double salary) {
        this->salary = salary;
    }
    double get_salary() {
        return salary;
    }
};
int main()
{


}
