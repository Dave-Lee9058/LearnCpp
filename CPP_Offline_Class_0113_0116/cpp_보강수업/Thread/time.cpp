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