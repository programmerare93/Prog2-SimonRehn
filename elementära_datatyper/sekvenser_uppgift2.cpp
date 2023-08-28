#include <string>
#include <iostream>

int main()
{
        std::string input;
        std::getline(std::cin, input);

        std::reverse(input.begin(), input.end());
        std::cout << input << '\n';

        return 0;
}
