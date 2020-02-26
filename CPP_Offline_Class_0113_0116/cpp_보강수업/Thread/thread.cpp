#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

#if 0

int main()
{
    /**
     * thread는 fucntion을 start하므로, method, lambda, functor 를 thread에 매개 변수로 넣을 수 있다.
     */
    std::thread th([](){ 
            for(int i = 0; i < 5; ++i)
            {
                std::cout << "Hello C++ Thread!!" << std::endl;
            }
            
        });
    
    for(int i = 1; i < 5; i++)
    {
        std::cout << "Hello Main ## " << std::endl;
    }

    // th.detach(); // Detaches the thread represented by the object from the calling thread, allowing them to execute independently from each other.
    th.join(); // th thread 종료시 까지 대기

    return 0;
}

#endif

#if 0



void work()
{
    for(int i = 0;i < 5; i++)
    {
        std::cout << "Hello thread \n";
    }
}

int main()
{
    std::thread th(work);

    for(int i = 0; i < 5; i ++)
    {
        std::cout << "Hello Main \n";
    }

    th.join();
}

#endif

#if 0

struct Worker {
    void operator()()
    {
        for(int i = 0;i < 5; i++)
        {
            std::cout << "Hello thread !! \n";
        }
    }
};

int main()
{
    Worker wk;
    std::thread th(wk);

    for(int i = 0; i < 5; i ++)
    {
        std::cout << "Hello Main ## \n";
    }

    th.join();
}

#endif

#if 0

int main()
{
    std::thread th;

    th = std::thread([](){
        for(int i = 0; i < 5; i ++)
        {
            std::cout << "Hello thread ## \n";
        }
    });

    th.join();
}

#endif

#if 0

int main()
{
    std::thread th([](int nparm){
        for(int i = 0; i < 10; ++i)
        {
            std::cout << "Thread Called " << nparm << "\n";
        }
    }, 5); // std::thread에 함수명, 함수매개변수 순서로 넣어주면 됨.

    th.join();
}

#endif

#if 0

class ThreadParam
{
public:
    void func()
    {
        for(int i = 0; i < 10; i++)
        {
            std::cout << "Thread Param \n";
        }
    }

    void func2(int n)
    {
        for(int i = 0; i < 10; i++)
        {
            std::cout << "Thread Param, Value n : " << n << '\n';
        }
    }

private:

};

int main()
{
    ThreadParam tparam;

    std::thread th(&ThreadParam::func, tparam); // Class의 func을 thread로 돌리기 위해서는 function point와 object를 넣어주면 됨. 

    std::thread th1(&ThreadParam::func2, tparam, 20);

    // th.join();
    // th1.join();

    std::cout << th.get_id() << '\n'; 
    std::cout << "Main Thread Id : " << this_thread::get_id() << '\n';

    if(th.joinable() == true)
    {
        th.join();
    }

    if(th1.joinable())
    {
        th1.join();
    }
}

#endif

#if 0
// detach

int main()
{
    std::thread th ([](int n){
        for(int i = 0; i < 5; ++i)
        {
            std::cout << "Thread Called " << n << '\n';
        }
    }, 10);

    th.detach();
    th.join(); // error : 분리되어 대기 불가능.

    for(int i = 0; i < 5; i++)
    {
        std::cout << "I am Main \n" ;
    }
}

#endif

#if 0
/**
 *  일시중지 
 *  sleep_for : 지정된 시간 동안 
 *  sleep_until : 지정 시간 까지 
 */

#include <chrono>

void countProc()
{
    for(int i = 0; i < 10; i++)
    {
        std::cout << i << '\n';
        // this_thread::sleep_for(std::chrono::duration<int>(1)); // c++11
        // this_thread::sleep_for(1s); // c++14;
        // this_thread::sleep_for(std::chrono::microseconds(200));
        this_thread::sleep_for(500ms); 
    }
}

int main()
{
    std::thread th (countProc);

    th.join();

    return 0;
}

#endif

#if 0

// sleep_until

#include <iostream>
#include <thread>
#include <chrono>

std::chrono::system_clock::time_point getTime()
{
    std::tm timeout_tm = {0};
    timeout_tm.tm_year = 2020 - 1900;
    timeout_tm.tm_mon = 7 - 1;
    timeout_tm.tm_mday = 10;
    timeout_tm.tm_hour = 14;
    timeout_tm.tm_min = 0;
    timeout_tm.tm_sec = 1;
    timeout_tm.tm_isdst = -1;

    std::time_t timeout_time_t = std::mktime(&timeout_tm);

    std::chrono::system_clock::time_point timeout_tp = std::chrono::system_clock::from_time_t(timeout_time_t);
    return timeout_tp;

}

int main()
{
    for(int i = 0; i < 10; i ++)
    {
        std::cout << i << '\n';
        std::this_thread::sleep_until(getTime());
    }
}

#endif

#if 0

//thread 종료

bool g_IsRunThread;

void threadFun()
{
    int i  = 0;

    while(g_IsRunThread)
    {
        //...
        std::cout << i << '\n';
        std::this_thread::sleep_for(1s);

    }
}

int main()
{
    g_IsRunThread = true;
    std::thread th(threadFun);

    //....
    std::this_thread::sleep_for(500ms);

    g_IsRunThread = false;
    th.join();
}

#endif

#if 0

std::mutex mtx;

int count;

void countProc(int no)
{
    int proCount;

    for(int i = 0; i < 10;++i)
    {
        mtx.lock();
        proCount = count;
        std::cout << "Thread NO : " << no <<  " Count : " << ++proCount << '\n';
        count = proCount;
        mtx.unlock();
        std::this_thread::sleep_for(std::chrono::duration<int>(1));
    }
}

int main()
{
    std::thread th1 (countProc, 1);
    std::thread th2 (countProc, 2);
    
    th1.join();
    th2.join();

    std::cout << "count result : " << count << '\n';

}

#endif


#if 0

#include <functional>

std::mutex mtx;

// int count = 0;

int main()
{
    int count = 0;

    auto cp = [&](int no) {
        int proCount;

        for(int i = 0; i < 10;++i)
        {
            mtx.lock();
            proCount = count;
            std::cout << "Thread NO : " << no <<  " Count : " << ++proCount << '\n';
            count = proCount;
            mtx.unlock();
            std::this_thread::sleep_for(std::chrono::duration<int>(1));
        }
    };

    std::thread th1 (cp, 1);
    std::thread th2 (cp, 2);
    
    th1.join();
    th2.join();

    std::cout << "count result : " << count << '\n';

}

#endif

#if 0

std::mutex mtx;

// int count = 0;

int main()
{
    int count = 0;

    auto cp = [&](int no) {
        int proCount;

        for(int i = 0; i < 10;++i)
        {
            {
                // mtx.lock();
                std::lock_guard<mutex> lck(mtx); // scope를 벗어날 때 자동으로 unlock을 호출 
                proCount = count;
                std::cout << "Thread NO : " << no <<  " Count : " << ++proCount << '\n';
                count = proCount;
                // mtx.unlock();
            }
            std::this_thread::sleep_for(std::chrono::duration<int>(1));
            
        }
    };

    std::thread th1 (cp, 1);
    std::thread th2 (cp, 2);
    
    th1.join();
    th2.join();

    std::cout << "count result : " << count << '\n';

}

#endif

#if 0

// once_flag, call_once

std::once_flag flag;

void test()
{
    std::cout << "Test Call \n";
}

int main()
{
    for(int i = 0; i < 5; ++i)
    {
        // test(); // 5번 호출 5번 실행
        std::call_once(flag, test); // 5번 호출에 1번 실행
    }
}

#endif

#if 1

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
    // std::mutex mtx;
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

#endif