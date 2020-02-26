
#include <functional>
#include <mutex>
#include <thread>
#include <iostream>

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
