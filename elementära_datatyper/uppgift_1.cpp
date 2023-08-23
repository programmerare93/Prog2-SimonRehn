#include <cmath>
#include <iostream>
#include <cstdio>

struct Time {
        Time(int hour, int minute) : hour(hour), minute(minute) {}

        void print_time() const;
        void increment_time();

        int hour;
        int minute;
};

void Time::print_time() const
{
        std::cout << "The time is: " << hour << ":" << minute << std::endl;
}

void Time::increment_time()
{
        minute += 1;
        if (minute >= 60) {
                hour += 1;
                minute -= 60;
        }

        if (hour >= 24) {
                hour = 0;
        }
}

int main()
{
        // 10:07
        Time current_time(10, 39);

        /* Måste inkrementera tiden 10^100 gånger */

        unsigned __int128 googol = 1;

        for (int i = 0; i < 100; ++i) {
                googol *= 10;
        }

        std::printf("%zu\n", googol);

        return 0;
}
