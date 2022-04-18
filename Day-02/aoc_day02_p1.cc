/*
 * @file aoc_day02_p1.cc
 * @brief Advent of Code (AOC) 2015 Puzzle solution for:  Day 02 Part 1.
 *
 * @author simon rowe <simon@wiremoons.com>
 * @license open-source released under "MIT License"
 *
 * @date originally created: 14 March 2022
 *
 * @details Advent of Code (AOC) 2015 Puzzle solution. See:
 * https://adventofcode.com/2015/
 */

//
// Build with:
// clang++ -std=c++20 -Wall -o aoc_day02_p1 aoc_day02_p1.cc
//

#include <array>
#include <fstream>
#include <iostream>
#include <string>

int main()
{

    std::string line;
    std::ifstream input_file;

    int length = 0, width = 0, height = 0, surface = 0, total_surface = 0, count = 0;
    char delim;

    // Switch comments for 'test'  vs  'final' data file
    // input_file.open("./data/day02-TEST-input.txt", std::ios::in);
    input_file.open("./data/day02-input.txt", std::ios::in);

    if (!input_file.is_open()) {
        std::cout << "Error opening puzzle date input file. Aborted." << std::endl;
        std::exit(1);
    }
    while (input_file >> length >> delim >> width >> delim >> height) {

        surface = (2 * (length * width)) + (2 * (length * height)) + (2 * (width * height));

        std::array<int, 3> items = {length, width, height};
        std::sort(items.begin(), items.end());

        surface = surface + (items[0] * items[1]);

        total_surface = total_surface + surface;

        surface = 0;
        count++;
    }

    std::cout << std::endl << "Advent Of Code 2015 :  Day 02 Part 01" << std::endl << std::endl;
    std::cout << "  » Calculated surface area for total of '" << count << "' items." << std::endl;
    std::cout << "  » PUZZLE ANSWER: surface areas total: " << total_surface << std::endl << std::endl;
}
