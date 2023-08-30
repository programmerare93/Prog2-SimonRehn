#include <string>
#include <iostream>

#include <cassert>

int main()
{
        std::cout << "Ange antal test fall: ";

        std::string input;
        std::getline(std::cin, input);

        int t = std::stoi(input);
        assert(t <= 100 && t >= 1);

        return 0;
}
