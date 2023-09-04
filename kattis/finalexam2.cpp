#include <vector>
#include <iostream>

int calculate_hanhs_score(std::vector<char> const& answers)
{
        int score = 0;
        for (auto iter = answers.cbegin(); iter != answers.cend(); ++iter) {
                char correct_answer = *iter;
                char hanhs_answer = *(iter + 1);
                if (hanhs_answer == correct_answer) {
                        ++score;
                }
        }

        return score;
}

int main()
{
        int num_of_questions;
        std::cin >> num_of_questions;

        std::vector<char> answers;
        for (int i = 0; i < num_of_questions; ++i) {
                char answer;
                std::cin >> answer;
                answers.push_back(answer);
        }

        std::cout << calculate_hanhs_score(answers) << std::endl;

        return 0;
}
