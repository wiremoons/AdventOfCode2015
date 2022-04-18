/*
 * @file aoc_day03_p2.cc
 * @brief Advent of Code (AOC) 2015 Puzzle solution for:  Day 03 Part 2.
 *
 * @author simon rowe <simon@wiremoons.com>
 * @license open-source released under "MIT License"
 *
 * @date originally created: 16 March 2022
 *
 * @details Advent of Code (AOC) 2015 Puzzle solution. See:
 * https://adventofcode.com/2015/
 */

//
// Build with:
// clang++ -std=c++20 -Wall -o aoc_day03_p2 aoc_day03_p2.cc
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string line;
    std::ifstream input_file;

    std::vector<std::pair<int, int>> coords_v;
    int deliveries = 2, santa_x = 0, santa_y = 0, robot_x = 0, robot_y = 0;
    bool santa = true;

    // Switch comments for 'test'  vs  'final' data file
    // input_file.open("./data/day03-TEST-input.txt", std::ios::in);
    input_file.open("./data/day03-input.txt", std::ios::in);

    if (!input_file.is_open()) {
        std::cout << "Error opening puzzle date input file. Aborted." << std::endl;
        std::exit(1);
    }

    // add starting location (same for both sanata & robot)
    coords_v.push_back({santa_x, santa_y});

    // read all directions, convert to 'x,y' co-ordinate pairs, add pairs to a
    // vector
    while (std::getline(input_file, line)) {
        for (auto &ch : line) {
            if (ch == '>')
                santa ? coords_v.push_back({santa_x++, santa_y}) : coords_v.push_back({robot_x++, robot_y});
            if (ch == '<')
                santa ? coords_v.push_back({santa_x--, santa_y}) : coords_v.push_back({robot_x--, robot_y});
            if (ch == '^')
                santa ? coords_v.push_back({santa_x, santa_y++}) : coords_v.push_back({robot_x, robot_y++});
            if (ch == 'v')
                santa ? coords_v.push_back({santa_x, santa_y--}) : coords_v.push_back({robot_x, robot_y--});
            // std::cout << "Delivery by: " << (santa ? "santa" : "robot");
            // std::cout << " at co-ords: " << (santa ? santa_x : robot_x) <<
            // "," << (santa ? santa_y : robot_y) << std::endl;
            deliveries++;
            // switch between santa and robot each move
            santa ? santa = false : santa = true;
        }
    }

    // must sort first for unique to work
    std::sort(coords_v.begin(), coords_v.end());
    // just use unique co-ordinates only so each house location is show once
    coords_v.erase(std::unique(coords_v.begin(), coords_v.end()), coords_v.end());

    std::cout << std::endl << "Advent Of Code 2015 :  Day 03 Part 02" << std::endl << std::endl;
    std::cout << "  » Number of deliveries total: '" << deliveries << "'" << std::endl;
    std::cout << "  » PUZZLE ANSWER: unique number of houses delivered too: " << coords_v.size() << std::endl
              << std::endl;

    input_file.close();
    std::exit(0);
}
