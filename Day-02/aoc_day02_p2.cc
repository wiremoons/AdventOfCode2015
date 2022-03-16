/*
 * @file aoc_day02_p2.cc
 * @brief Advent of Code (AOC) 2015 Puzzle solution for:  Day 02 Part 2.
 *
 * @author simon rowe <simon@wiremoons.com>
 * @license open-source released under "MIT License"
 *
 * @date originally created: 16 March 2021
 *
 * @details Advent of Code (AOC) 2015 Puzzle solution. See:
 * https://adventofcode.com/2015/
 */

//
// Build with:
// clang++ -std=c++20 -Wall -o aoc_day02_p2 aoc_day02_p2.cc
//

#include <fstream>
#include <iostream>
#include <string>
#include <array>

int main()
{

    std::string line;
    std::ifstream input_file;

    int length = 0, width = 0, height = 0, ribbon = 0, total_ribbon = 0, count = 0;
    char delim;

 	// Switch comments for 'test'  vs  'final' data file
 	//input_file.open("./data/day02-TEST-input.txt", std::ios::in);
    input_file.open("./data/day02-input.txt", std::ios::in);
    
    if (!input_file.is_open()) {
    	std::cout << "Error opening puzzle date input file. Aborted." << std::endl;
    	std::exit(1);
    }
    
	while (input_file >> length >> delim >> width >> delim >> height) {
	
		ribbon = (length * width * height);
		
		std::array<int, 3> items = {length, width, height};
		std::sort(items.begin(), items.end());
		
		ribbon = ribbon + (items[0] + items[0] + items[1] + items[1]);

		total_ribbon = total_ribbon + ribbon;
		
		ribbon = 0;
		count++;		
	}
    
    std::cout << std::endl
              << "Advent Of Code 2015 :  Day 02 Part 01" << std::endl
              << std::endl;
    std::cout << "  » Calculated surface area for total of '" << count << "' items." << std::endl;
    std::cout << "  » PUZZLE ANSWER: ribbon length total: " << total_ribbon
              << std::endl
              << std::endl;
    
    input_file.close();          
    std::exit(0);
}
