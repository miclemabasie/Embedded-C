#include <iostream>
#include <chrono>
#include <filesystem>

int main(void)
{
    auto now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch());

    std::tm tm_buf{};

    localtime_r(&time_t_now, &tm_buf);

    std::ostringstream oss;
    oss << std::put_time(&tm_buf, "%Y-%m-%d %H:%M:%S") << "." << std::setfill('0') << std::setw(1) << ms.count();

    std::cout << oss.str();

    std::cout << "Time T in raw form: " << std::endl;
    std::cout << tm_buf.tm_hour;
}