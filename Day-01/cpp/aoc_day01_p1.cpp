/*
 * @file aoc_day01_p1.cpp
 * @brief Advent of Code (AOC) 2015 Puzzle solution for:  Day 01 Part 1.
 *
 * @author simon rowe <simon@wiremoons.com>
 * @license open-source released under "MIT License"
 *
 * @date originally created: 14 March 2021
 *
 * @details Advent of Code (AOC) 2015 Puzzle solution. See:
 * https://adventofcode.com/2015/
 */

//
// Build with:
// clang++ -std=c++20 -Wall -### -o aoc_day01_p1 aoc_day01_p1.cpp
//

#include <fstream>
#include <iostream>
#include <string>

int main()
{

    std::string line;
    std::ifstream input_file;

    int up = 0, down = 0, floor = 0;

    input_file.open("./data/day01-input.txt", std::ios::in);

    while (std::getline(input_file, line)) {
        for (auto &ch : line) {
            ch == '(' ? up++ &&floor++ : down++ &&floor--;
        }
    }

    std::cout << std::endl
              << "Advent Of Code 2015 :  Day 01 Part 01" << std::endl
              << std::endl;
    std::cout << "  » Moved up '" << up << "' and moved down '" << down
              << "' floors" << std::endl;
    std::cout << "  » Floor changes analysed: '" << down + up << "'"
              << std::endl;
    std::cout << "  » PUZZLE ANSWER: final floor is: " << floor << std::endl
              << std::endl;
}
