
#include <iostream>
#include <mutex>
#include <thread>


class Account
{
public:
    // friend std::ostream& operator<< (std::ostream o, const Account &acc);
    Account() = default;
    Account(std::string id, std::string name, int balance) : id(id), name(name), balance(balance) {}

    std::string getId() const { return id; }
    std::string getName() const { return name; }
    int getBalance() const { return balance; }

    void deposit(int money)
    {
        if(money > 0)
        {
            // std::lock_guard<std::mutex> lck(mtx);
            balance += money;
        }
    }

    void withdraw(int money)
    {
        if(balance >= money)
        {
            // std::lock_guard<std::mutex> lck(mtx);
            balance -= money;
        }
    }

    // Account& operator= (const Account &acc) 
    // {
    //     this->id = acc.id;
    //     this->name = acc.name;
    //     this->balance = acc.balance;
    //     return *this;
    // }

private:
    std::mutex mtx;
    std::string id;
    std::string name;
    int balance;
};

std::ostream& operator<< (std::ostream &o, const Account &acc)
{
    o << "Account : " << acc.getId() << " , name : " << acc.getName() << ", balance : " << acc.getBalance() << '\n';
    return o;
}

std::mutex mtx;

int main()
{
    Account acc("1001", "hong", 100000);

    auto deposit = [&](){
        Account a;
        for(int i = 0; i<1000; i++)
        {
            std::lock_guard<std::mutex> lck(mtx);
            a = acc;
            a.deposit(100);
            acc = a;
        }
    };

    auto withraw = [&](){
        Account a;
        for(int i = 0; i<1000; i++)
        {
            std::lock_guard<std::mutex> lck(mtx);
            a = acc;
            a.withdraw(100);
            acc = a;
        }
    };

    std::thread deposit_th(deposit);
    std::thread widraw_th(withraw);

    deposit_th.join();
    widraw_th.join();

    std::cout << acc << '\n';

}