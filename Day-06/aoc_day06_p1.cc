/*
 * @file aoc_day06_p1.cc
 * @brief Advent of Code (AOC) 2015 Puzzle solution for:  Day 06 Part 1.
 *
 * @author Simon Rowe <simon@wiremoons.com>
 * @license open-source released under "MIT License"
 *
 * @date originally created: 17 March 2021
 *
 * @details Advent of Code (AOC) 2015 Puzzle solution. See:
 * https://adventofcode.com/2015/
 */

//
// Build with:
// clang++ -std=c++20 -Wall -o aoc_day06_p1 aoc_day06_p1.cc
//   or
// g++ -std=c++20 -Wall -o aoc_day06_p1 aoc_day06_p1.cc
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

// Notes on input format:
//
// Input data state changes are: 'toggle' 'turn on' 'turn off'
// Range follows and is stated as:  887,9 through 959,629
// Full example line of input for context:
//    turn on 887,9 through 959,629

int main()
{

    std::string line;
    std::ifstream input_file;
    int count_changes{};
    int lights_on{};

    // Switch comments for 'test'  vs  'final' data file
    // input_file.open("./data/day06-TEST-input.txt", std::ios::in);
    input_file.open("./data/day06-input.txt", std::ios::in);

    if (!input_file.is_open()) {
        std::cout << "Error opening puzzle date input file. Aborted." << std::endl;
        std::exit(1);
    }

    // read all to detect directions, convert to 'x,y' co-ordinate pairs, add pairs to a
    // vector
    while (std::getline(input_file, line)) {
    }

    std::cout << std::endl << "Advent Of Code 2015 :  Day 06 Part 01" << '\n' << '\n';
    std::cout << "  » Number of switches analysed : '" << count_changes << "'" << '\n';
    std::cout << "  » PUZZLE ANSWER: number of 'lights on' are: " << lights_on << '\n' << std::endl;

    input_file.close();
    std::exit(0);
}
