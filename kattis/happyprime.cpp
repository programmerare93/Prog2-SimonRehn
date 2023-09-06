#include <array>
#include <string>
#include <vector>
#include <iostream>

int char_to_int(char c)
{
        return c - '0';
}

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

void square_ints(std::vector<int>& vec)
{
        for (int& num : vec) {
                num *= num;
        }
}

int ints_sum(std::vector<int> const& vec)
{
        int sum = 0;
        for (int num : vec) {
                sum += num;
        }

        return sum;
}

bool is_happy(int num)
{
        std::string num_str = std::to_string(num);

        std::vector<int> digits;
        for (char c : num_str) {
                digits.push_back(char_to_int(c));
        }

        square_ints(digits);
        /* Ifall summan blir 'num' igen kommer talet inte vara happy */
        while (ints_sum(digits) != 1 && ints_sum(digits) != num) {
                square_ints(digits);
        }

        if (ints_sum(digits) == 1) {
                return true;
        } else {
                return false;
        }
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

        /* Ser till så att sista nummeret i inputen läggs til*/
        arr[index] = std::stoi(num);

        return arr;

}

void handle_input(std::array<int, 2> const& input)
{
        int K = input[0];
        int m = input[1];

        if (is_prime(m)) {
                if (is_happy(m)) {
                        std::cout << K << ' ' << m << " YES\n";
                } else {
                        std::cout << K << ' ' << m << " NO\n";
                }
        } else {
                std::cout << K << ' ' << m << " NO\n";
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
