#include <string>
#include <iostream>

std::string food(std::string food, bool vegan = false)
{
        if (vegan) {
                return "soja" + food;
        } else {
                return food;
        }
}

int main()
{
        std::cout << food("mjölk") << std::endl;
        std::cout << food("mjölk", true) << std::endl;
        return 0;
}