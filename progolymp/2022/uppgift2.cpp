#include <array>
#include <string>
#include <iostream>

constexpr std::array<char, 6> vowels = {
        'a',
        'e',
        'i',
        'o',
        'u',
        'y'
};

bool is_vowel(char c)
{
        if (c == ' ') {
                return false;
        }

        for (char vowel : vowels) {
                if (c == vowel) {
                        return true;
                }
        }

        return false;
}

bool is_consonant(char c)
{
        if (c == ' ') {
                return false;
        }
        
        return !is_vowel(c);
}

bool is_short_vowel(std::string::const_iterator const& iter,
                    std::string const& str)
{
        if (iter == str.cend()
            || (iter + 1) == str.cend()
            || (iter + 2) == str.cend())
        {
                return false;
        }

        char c = *iter;
        char c1 = *(iter + 1);
        char c2 = *(iter + 2);

        if (is_vowel(c) && is_consonant(c1) && is_consonant(c2)) {
                return true;
        } else {
                return false;
        }
}

std::string translate(std::string const& sentence, int num_of_words)
{
        std::string current_word;
        std::string translated;

        for (auto iter = sentence.cend(); iter >= sentence.cbegin(); --iter) {
                char c = *iter;

                if (c != ' ') {
                        if (!is_short_vowel(iter, sentence)) {
                                current_word.push_back(c);
                        }
                } else {
                        translated.append(current_word + " ");
                        current_word.clear();
                }

                if (iter == sentence.cbegin()) {
                        translated.append(current_word);
                }
        }

        return translated;
}

int main()
{
        int num_of_words;
        std::string sentence;

        std::cout << "Antal ord? ";
        std::cin >> num_of_words;
        std::cin.ignore();
        std::cout << "Mening? ";
        std::getline(std::cin, sentence);

        std::cout << "Svar: " << translate(sentence, num_of_words) << std::endl;

        return 0;
}
