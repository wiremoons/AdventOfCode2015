/*
 * @file aoc_day07_p1.cc
 * @brief Advent of Code (AOC) 2015 Puzzle solution for:  Day 07 Part 1.
 *
 * @author Simon Rowe <simon@wiremoons.com>
 * @license open-source released under "MIT License"
 *
 * @date originally created: 18 March 2022
 *
 * @details Advent of Code (AOC) 2015 Puzzle solution. See:
 * https://adventofcode.com/2015/
 */

//
// Build with:
// clang++ -std=c++20 -Wall -o aoc_day07_p1 aoc_day07_p1.cc
//   or
// g++ -std=c++20 -Wall -o aoc_day07_p1 aoc_day07_p1.cc
//

#include <fstream>
#include <iostream>

// GLOBALS
// set if debug output is needed
bool debug{false};

///////////////////////////////////////////////////////////////////////////////
// Notes on input format:
//
// Input data state changes are: 'toggle' 'turn on' 'turn off'
// Range follows and is stated as:  887,9 through 959,629
// Full example line of input for context:
//    turn on 887,9 through 959,629
///////////////////////////////////////////////////////////////////////////////

/// @brief Count the total number of light in the 'on' state
/// @param light_status is a boolean grid (matrix) of lights to be checked
/// @ return the total number of lights that are on (ie set to true)
int totalLightsOn()
{
    int result{0};

    return result;
}

///////////////////////////////////////////////////////////////////////////////
//                         MAIN ENTRY POINT                                  //
///////////////////////////////////////////////////////////////////////////////

int main()
{
    // puzzle input file stream
    std::ifstream input_file{};

    // Switch comments for 'test'  vs  'final' data file
    // input_file.open("./data/day07-TEST-input.txt", std::ios::in);
    input_file.open("./data/day07-input.txt", std::ios::in);

    if (not input_file.is_open()) {
        std::cerr << "Error opening puzzle date input file. Aborted." << std::endl;
        std::exit(1);
    }

    // variables to hold input data
    std::string line{};
    int line_number{0};
    int count_changes{0};
    int lights_on{0};

    //  read each line delimited by '\n' into 'line' from the file
    while (std::getline(input_file, line)) {
        line_number++;
    }

    std::cout << std::endl << "Advent Of Code 2015 :  Day 07 Part 01" << '\n' << '\n';
    std::cout << "  » Number of switches analysed : '" << count_changes << "'" << '\n';
    std::cout << "  » PUZZLE ANSWER: number of 'lights on' are: " << lights_on << '\n' << std::endl;

    // Part 1 Answer : 377891

    input_file.close();
    std::exit(0);
}
