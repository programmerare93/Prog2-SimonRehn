#include <cmath>
#include <iostream>
#include <cstdio>

struct Time {
        Time(int hour, int minute) : hour(hour), minute(minute) {}

        void print_time() const;

        int hour;
        int minute;
};

void Time::print_time() const
{
        std::cout << "The time is: " << hour << ":" << minute << std::endl;
}

int main()
{
        // 10:07
        Time current_time(10, 39);

        /* går inte att representer en googol med 128 bitar */
        unsigned __int128 googol = 1;

        for (int i = 0; i < 100; ++i) {
                googol *= 10;
        }

        std::printf("%zu\n", googol); /* Är inte en googol utan värdet har överflödit */

        return 0;
}
