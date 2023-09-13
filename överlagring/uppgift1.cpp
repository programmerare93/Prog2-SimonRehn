#include <iostream>

template <typename... Args>
int add_this(Args... args)
{
        int sum = 0;
        for (int num : {args...}) {
                sum += num;
        }

        return sum;
}

int main()
{
        std::cout << add_this(1, 2, 3, 4, 5) << std::endl;
        return 0;
}
