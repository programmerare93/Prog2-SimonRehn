#include <iostream>

unsigned long long time_for_green_cards(unsigned long N)
{
        return N * 10;
        //return ((N / 2) * 20 + (N % 2) * 10);
}

/* Använder long long för att garantera att tiden för plats för stora tal */
unsigned long long time_required(unsigned long N, unsigned long M)
{
        if (M == 0) {
                return time_for_green_cards(N);
        }

        unsigned long long time_passed = 0;

        return time_passed;
}

int main()
{
        unsigned long N, M;
        std::cout << "Antal med grönt kort? ";
        std::cin >> N;
        std::cout << "Antal utan grönt kort? ";
        std::cin >> M;

        std::cout << "Svar: " << time_required(N, M) << std::endl;

        return 0;
}
