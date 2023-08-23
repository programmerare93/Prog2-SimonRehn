#include <string>
#include <iostream>

int main()
{
        std::string float_str = "3.14";
        /* stof står för: string to float */
        float actual_float = std::stof(float_str);

        /* Skriver ut: "float_str: 3.14, actual_float: 3.14" */
        std::cout << "float_str: " << float_str
                  << ", actual_float: " << actual_float << '\n';

        return 0;
}
