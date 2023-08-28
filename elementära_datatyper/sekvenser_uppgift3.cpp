#include <string>
#include <iostream>
#include <unordered_map>

int main()
{
        std::unordered_map<std::string, std::string> capitals {
                {"Sverige", "Stockholm"},
                {"Norge", "Oslo"},
                {"Finland", "Helsingborg"}
        };
        capitals.insert({"Danmark", "Köpenhamn"});
        capitals.erase("Finland");

        for (auto const& kv_pair : capitals) {
                std::cout << kv_pair.first << ": " << kv_pair.second << '\n';
        }
        return 0;
}
