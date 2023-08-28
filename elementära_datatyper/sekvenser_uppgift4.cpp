#include <set>
#include <string>
#include <iostream>

int main()
{
        std::set<std::string> first_set {"Banan", "Päron", "Äpple"};
        std::set<std::string> second_set {"Kiwi", "Ananas", "Päron"};

        first_set.merge(second_set); /* merge kräver C++17 eller högre */
        std::cout << first_set.size() << '\n'; /* skriver ut '5' */
        return 0;
}
