/*
 * @file aoc_day05_p1.cc
 * @brief Advent of Code (AOC) 2015 Puzzle solution for:  Day 05 Part 02
 *
 * @author simon rowe <simon@wiremoons.com>
 * @license open-source released under "MIT License"
 *
 * @date originally created: 17 March 2021
 *
 * @details Advent of Code (AOC) 2015 Puzzle solution. See:
 * https://adventofcode.com/2015/
 */

//
// Build with:
// clang++ -std=c++20 -Wall -Werror -pedantic -fsanitize=undefined -o aoc_day05_p2 aoc_day05_p2.cc
// or use: make
//
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

/// Check if the provided input string contains any of the banned strings
/// Return true if banned string is found in the input
bool has_banned(const std::string &input, const std::string &double_str)
{
    size_t found{0};
    const std::string b1 = "ab";
    const std::string b2 = "cd";
    const std::string b3 = "pq";
    const std::string b4 = "xy";

    // std::cout << "checking '" << input << "' in ab, cd, pq, or xy" <<
    // std::endl;

    found = input.find(double_str);
    if (found != std::string::npos)
        return true;

    found = input.find(b2);
    if (found != std::string::npos)
        return true;

    found = input.find(b3);
    if (found != std::string::npos)
        return true;

    found = input.find(b4);
    if (found != std::string::npos)
        return true;

    // std::cout << "No banned found." << std::endl;

    return false;
}

bool has_double_letter_spaced(const std::string &input)
{
    bool double_letter = false;
    size_t inputSize = input.size();
    for (size_t i = 0; i < (inputSize - 1); ++i) {
        char currLetter = input[i];
        char nextLetter = input[i + 1];
        if (currLetter == nextLetter) {
            double_letter = true;
            break;
        }
    }

    return double_letter;
}

int main()
{
    std::string line;
    std::ifstream input_file;

    int count_str{0}, nice_final_count{0}, nice_tracker{0};

    // Switch comments for 'test'  vs  'final' data file
    input_file.open("./data/day05-TEST-input2.txt", std::ios::in);
    // input_file.open("./data/day05-input.txt", std::ios::in);

    if (!input_file.is_open()) {
        std::cout << "Error opening puzzle date input file. Aborted." << std::endl;
        std::exit(1);
    }

    // read all directions, convert to 'x,y' co-ordinate pairs, add pairs to a
    // vector
    while (std::getline(input_file, line)) {

        // std::cout << std::endl << "Processing string : " << line <<
        // std::endl;

        // ensure string has a double letter sequence
        if (has_double_letter_spaced(line)) {
            nice_tracker++;
        }

        // if analysed string is 'nice' add to overall total
        if (nice_tracker >= 1) {
            nice_final_count++;
        }

        // increment count of strings analysed
        count_str++;
        // reset per loop nice string tracker
        nice_tracker = 0;
    }

    std::cout << std::endl << "Advent Of Code 2015 :  Day 05 Part 02" << std::endl << std::endl;
    std::cout << "  » Number of strings analysed : '" << count_str << "'" << std::endl;
    std::cout << "  » PUZZLE ANSWER: number of 'nice' strings: " << nice_final_count << std::endl << std::endl;

    input_file.close();
    std::exit(0);
}
