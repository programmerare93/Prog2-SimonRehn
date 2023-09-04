#include <array>
#include <string>
#include <iostream>

bool is_prime(int num)
{
        if (num <= 1) {
                return false;
        }

        for (size_t i = 2; i < num; ++i) {
                if (num % i == 0) {
                        return false;
                }
        }

        return true;
}

std::array<int, 2> parse_input(std::string const& input)
{
        /* NOTE: Antar att inputen är korrekt */

        size_t index = 0;
        std::array<int, 2> arr;

        std::string num;
        for (auto iter = input.cbegin(); iter != input.cend(); ++iter) {
                char c = *iter;
                if (c != ' ') {
                        num.push_back(c);
                } else {
                        arr[index] = std::stoi(num);
                        ++index;
                        num.clear();
                }
        }

        return arr;

}

void handle_input(std::array<int, 2> const& input)
{
        int K = input[0];
        int m = input[1];

        if (is_prime(m)) {
                std::cout << "Prime\n";
        } else {
                std::cout << "Not Prime\n";
        }
}

int main()
{
        int P;
        std::cin >> P;
        std::cin.ignore();

        for (int i = 0; i < P; ++i) {
                std::string input;
                std::getline(std::cin, input);
                handle_input(parse_input(input));
        }
        return 0;
}
