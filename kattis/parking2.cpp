#include <string>
#include <vector>
#include <iostream>

#include <cassert>

std::vector<int> str_to_ints(std::string const& str)
{
        std::vector <int> ints;

        std::string number;
        for (std::size_t i = 0; i < str.length(); ++i) {
                char c = str[i];
                if (c != ' ') {
                        number.push_back(c);
                } else {
                        ints.push_back(std::stoi(number));
                        number.clear();
                }
        }

        return ints;
}

int main()
{
        std::cout << "Ange antal test fall: ";

        std::string input;
        std::getline(std::cin, input);

        int num_of_test_cases = std::stoi(input);
        assert(num_of_test_cases <= 100 && num_of_test_cases >= 1);

        for (int i = 0; i < num_of_test_cases; ++i) {
                std::cout << "Ange antal butiker: ";
                std::getline(std::cin, input);

                int num_of_stores = std::stoi(input);
                assert(num_of_stores <= 20 && num_of_stores >= 1);

                std::cout << "Ange butikernas positioner: ";
                std::getline(std::cin, input);

                std::vector<int> store_positions = str_to_ints(input);

                for (int i : store_positions) {
                        assert(i <= 99 && i >= 0);
                }
        }

        return 0;
}
