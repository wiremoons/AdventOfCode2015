/*
 * @file aoc_day05_p1.cc
 * @brief Advent of Code (AOC) 2015 Puzzle solution for:  Day 05 Part 1.
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
// clang++ -std=c++20 -Wall -o aoc_day05_p1 aoc_day05_p1.cc
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

// does the string contain three of: aeiou?
bool has_three_vowels(const std::string &input)
{

    long count{0};
    const std::string vowels = "aeiouAEIOU";

    for (auto &ch : input) {
        // std::cout << "checking '" << ch << "' in " << vowels << std::endl;
        count = count + std::count(vowels.cbegin(), vowels.cend(), ch);
    }
    // std::cout << "Number of vowels found: " << count << std::endl;
    return (count >= 3);
}

bool has_double_letter(const std::string &input)
{
    bool doubleletter = false;
    size_t inputSize = input.size();
    for (size_t i = 0; i < (inputSize - 1); ++i) {
        char currLetter = input[i];
        char nextLetter = input[i + 1];
        if (currLetter == nextLetter) {
            doubleletter = true;
            break;
        }
    }

    return doubleletter;
}

// input does NOT contain the strings ab, cd, pq, or xy
bool has_banned(const std::string &input)
{
    size_t found{0};
    const std::string b1 = "ab";
    const std::string b2 = "cd";
    const std::string b3 = "pq";
    const std::string b4 = "xy";

    // std::cout << "checking '" << input << "' in ab, cd, pq, or xy" <<
    // std::endl;

    found = input.find(b1);
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

int main()
{

    std::string line;
    std::ifstream input_file;

    int count_str{0}, nice_final_count{0}, nice_tracker{0};

    // Switch comments for 'test'  vs  'final' data file
    // input_file.open("./data/day05-TEST-input.txt", std::ios::in);
    input_file.open("./data/day05-input.txt", std::ios::in);

    if (!input_file.is_open()) {
        std::cout << "Error opening puzzle date input file. Aborted." << std::endl;
        std::exit(1);
    }

    // read all directions, convert to 'x,y' co-ordinate pairs, add pairs to a
    // vector
    while (std::getline(input_file, line)) {

        // std::cout << std::endl << "Processing string : " << line <<
        // std::endl;

        // ensure string has 3 or more vowels
        if (has_three_vowels(line)) {
            nice_tracker++;
        }

        // ensure string has a double letter sequence
        if (has_double_letter(line)) {
            nice_tracker++;
        }

        // ensure string does NOT have banned strings
        if (!has_banned(line)) {
            nice_tracker++;
        }

        // if analysed string is 'nice' add to overall total
        if (nice_tracker >= 3) {
            nice_final_count++;
        }

        // increment count of strings analysed
        count_str++;
        // reset per loop nice string tracker
        nice_tracker = 0;
    }

    std::cout << std::endl << "Advent Of Code 2015 :  Day 05 Part 01" << std::endl << std::endl;
    std::cout << "  » Number of strings analysed : '" << count_str << "'" << std::endl;
    std::cout << "  » PUZZLE ANSWER: number of 'nice' strings: " << nice_final_count << std::endl << std::endl;

    input_file.close();
    std::exit(0);
}
