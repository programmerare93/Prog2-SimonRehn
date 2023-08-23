#include <iostream>

int main()
{
        int a, b;
        std::cin >> a >> b;

        int larger_num, smaller_num;
        if (a > b) {
                larger_num = a;
                smaller_num = b;
        } else {
                larger_num = b;
                smaller_num = a;
        }

        std::cout << smaller_num << " " << larger_num << '\n';

        return 0;
}
