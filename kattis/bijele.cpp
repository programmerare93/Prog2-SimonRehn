#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <iostream>

constexpr int num_of_kings = 1;
constexpr int num_of_queens = 1;
constexpr int num_of_rooks = 2;
constexpr int num_of_bishops = 2;
constexpr int num_of_knights = 2;
constexpr int num_of_pawns = 8;

const std::vector<int> piece_nums {
        num_of_kings,
        num_of_queens,
        num_of_rooks,
        num_of_bishops,
        num_of_knights,
        num_of_pawns
};

using ChessPieces = std::vector<int>;

ChessPieces parse_input(std::string const& input)
{
        std::istringstream iss(input);
        return ChessPieces(std::istream_iterator<int>(iss),
                           std::istream_iterator<int>());
        /*
        ChessPieces pieces;
        std::size_t index = 0;

        for (char c : input) {
                if (c != ' ') {
                        
                        pieces[index] = std::atoi(&c);
                        ++index;
                }
        }

        return pieces;
        */
}

void check_pieces(ChessPieces const& pieces)
{
        std::string output;

        for (std::size_t i = 0; i < pieces.size(); ++i) {
                int num_of_piece = pieces[i];
                int canon_num_of_piece = piece_nums[i];
                if (num_of_piece != canon_num_of_piece) {
                        output += (std::to_string(canon_num_of_piece - num_of_piece)
                                   + " ");
                } else {
                        output += "0 ";
                }

        }

        std::cout << output << std::endl;
}

int main()
{
        std::string input;
        std::getline(std::cin, input);
        check_pieces(parse_input(input));
        return 0;
}
