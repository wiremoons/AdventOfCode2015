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

#include <fstream>
#include <iostream>
#include <numeric>
#include <ostream>
#include <vector>

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
int total_lights_on(std::vector<std::vector<bool>> const &light_status)
{
    int result{0};
    for (const auto &row : light_status) {
        for (const auto &col : row) {
            if (col) {
                result++;
            }
        }
    }
    return result;
}

/// @brief Alter the current light setting to it opposite setting
/// @param light_status reference to a boolean grid (matrix) of lights to be toggled
/// @ return
void toggle_lights(std::vector<std::vector<bool>> &light_status)
{

    for (size_t i{0}; i < light_status.size(); i++) {
        for (size_t j{0}; j < light_status[i].size(); j++) {
            // light_status.at(i).at(j).flip(); // bounds check version
            light_status[i][j].flip();
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
//                         MAIN ENTRY POINT                                  //
///////////////////////////////////////////////////////////////////////////////
int main()
{
    std::string line{};
    std::ifstream input_file{};
    // 0-999 grid if bool to track light on/off status - initialised to off
    std::vector<std::vector<bool>> light_status{1000, std::vector<bool>(1000, false)};
    int count_changes{};
    int lights_on{};

    lights_on = total_lights_on(light_status);
    std::cout << "Initial lights on are: " << lights_on << '\n';
    toggle_lights(light_status);

    // Switch comments for 'test'  vs  'final' data file
    // input_file.open("./data/day06-TEST-input.txt", std::ios::in);
    input_file.open("./data/day06-input.txt", std::ios::in);

    if (not input_file.is_open()) {
        std::cerr << "Error opening puzzle date input file. Aborted." << std::endl;
        std::exit(1);
    }

    // read all to detect directions, convert to 'x,y' co-ordinate pairs, add pairs to a
    // vector
    while (std::getline(input_file, line)) {
    }

    // final check of total on
    lights_on = total_lights_on(light_status);

    std::cout << std::endl << "Advent Of Code 2015 :  Day 06 Part 01" << '\n' << '\n';
    std::cout << "  » Number of switches analysed : '" << count_changes << "'" << '\n';
    std::cout << "  » PUZZLE ANSWER: number of 'lights on' are: " << lights_on << '\n' << std::endl;

    input_file.close();
    std::exit(0);
}
