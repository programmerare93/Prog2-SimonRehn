#include <array>
#include <string>
#include <iostream>

/*
  \x86 = å
  \x84 = ä
  \x94 = ö
*/
std::array<char, 9> const vowels {'a', 'e', 'i', 'o', 'u', 'y',
                                  '\x86', '\x84', '\x94'};

bool is_vowel(char c) {
        return std::find(vowels.cbegin(), vowels.cend(), c) != vowels.cend();
}

std::string translate(std::string const& sentence)
{
        std::string translated_sentence;

        for (char c : sentence) {
                if (!is_vowel(tolower(c)) && c != ' ') {
                        translated_sentence += c;
                        translated_sentence += 'o';
                        translated_sentence += c;
                } else {
                        translated_sentence += c;
                }
        }
        return translated_sentence;
}

int main()
{
        std::cout << "Skriv in en mening: ";

        std::string input;
        std::getline(std::cin, input);
        std::cout << "I r\x94varspr\x86k \x84r det: " << translate(input) << '\n';

        return 0;
}
