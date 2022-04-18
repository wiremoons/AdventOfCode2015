/*
 * @file aoc_day06_p1.cc
 * @brief Advent of Code (AOC) 2015 Puzzle solution for:  Day 06 Part 1.
 *
 * @author Simon Rowe <simon@wiremoons.com>
 * @license open-source released under "MIT License"
 *
 * @date originally created: 17 March 2022
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

#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

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
int totalLightsOn(std::vector<std::vector<bool>> const &light_status)
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
/// @ return no return value (void)
void toggleLights(std::vector<std::vector<bool>> &light_status)
{

    for (size_t i{0}; i < light_status.size(); i++) {
        for (size_t j{0}; j < light_status[i].size(); j++) {
            // light_status.at(i).at(j).flip(); // bounds check version
            light_status[i][j].flip();
        }
    }
}

/// @brief Alter the current light setting to it opposite setting
/// @param light_status reference to a boolean grid (matrix) of lights to be toggled
/// #param points of int point_i{0}, point_j{0}, point_k{0}, point_m{0};
/// @ return no return value (void)
void LightsAsActionToggle(std::vector<std::vector<bool>> &light_status, std::vector<int> points)
{
    if (debug) {
        std::cout << "Executing action: 'toggle'\n\n";
    }
    for (size_t i = points.at(0); i <= points.at(2); i++) {
        for (size_t j = points.at(1); j <= points.at(3); j++) {
            // light_status.at(i).at(j).flip(); // bounds check version
            light_status[i][j].flip();
        }
    }
}

/// @brief Alter the current light setting to it opposite setting
/// @param light_status reference to a boolean grid (matrix) of lights to be toggled
/// #param points of int point_i{0}, point_j{0}, point_k{0}, point_m{0};
/// @ return no return value (void)
void LightsAsActionOn(std::vector<std::vector<bool>> &light_status, std::vector<int> points)
{
    if (debug) {
        std::cout << "Executing action: 'on'\n\n";
    }
    for (size_t i = points.at(0); i <= points.at(2); i++) {
        for (size_t j = points.at(1); j <= points.at(3); j++) {
            // light_status.at(i).at(j).flip(); // bounds check version
            if (light_status[i][j] == false) {
                light_status[i][j] = true;
            }
        }
    }
}

/// @brief Alter the current light setting to it opposite setting
/// @param light_status reference to a boolean grid (matrix) of lights to be toggled
/// #param points of int point_i{0}, point_j{0}, point_k{0}, point_m{0};
/// @ return no return value (void)
void LightsAsActionOff(std::vector<std::vector<bool>> &light_status, std::vector<int> points)
{
    if (debug) {
        std::cout << "Executing action: 'off'\n\n";
    }
    for (size_t i = points.at(0); i <= points.at(2); i++) {
        for (size_t j = points.at(1); j <= points.at(3); j++) {
            // light_status.at(i).at(j).flip(); // bounds check version
            if (light_status[i][j] == true) {
                light_status[i][j] = false;
            }
        }
    }
}

/// @brief Extract any integers from a string into a vector of int
/// @param string containing the integers to be extracted
/// @ return a vector containing the integers extracted
std::vector<int> getNumberFromString(std::string &s)
{
    std::string temp_str;      // hold conversion to int attempts
    std::vector<int> points{}; // extracted points as int
    std::stringstream ss;

    // convert the ',' to a 'space' between numbers convert to int cleanly
    std::replace(s.begin(), s.end(), ',', ' ');
    // move the string to a string stream
    ss << s;

    int temp_int;

    while (!ss.eof()) {
        // take each item / word into 'temp_str' one by one
        ss >> temp_str;
        try {
            // attempt to convert each item to an 'int' - store if ok
            temp_int = std::stoi(temp_str);
            points.push_back(temp_int);
        } catch (std::exception &e) {
            // exception on conversion so move on to next item
            continue;
        }
    }
    // check the correct number of integers were found
    if (points.size() != 4) {
        std::cerr << "Expected to extract four (4) integers - only got: " << points.size() << std::endl;
        std::exit(1);
    }
    // return any integers found in the string
    return points;
}

/// @brief Identify the switch action need from 'toggle'; 'on'; or 'off'.
/// @param string containing a line read from the the puzzle input
/// @ return -1 == error; 1 == toggle; 2 == on; 3 == off.
int getSwitchAction(std::string s)
{
    if (debug) {
        std::cout << "Searching for required action...  ";
    }

    std::string locate = "toggle";
    size_t found = s.find(locate);
    if (found != std::string::npos) {
        if (debug) {
            std::cout << "found 'toggle' at:" << found << std::endl;
        }
        return 1;
    }

    locate = "on";
    found = s.find(locate);
    if (found != std::string::npos) {
        if (debug) {
            std::cout << "found 'on' at:" << found << std::endl;
        }
        return 2;
    }

    locate = "off";
    found = s.find(locate);
    if (found != std::string::npos) {
        if (debug) {
            std::cout << "found 'off' at:" << found << std::endl;
        }
        return 3;
    }

    return -1;
}

///////////////////////////////////////////////////////////////////////////////
//                         MAIN ENTRY POINT                                  //
///////////////////////////////////////////////////////////////////////////////

int main()
{
    // puzzle input file stream
    std::ifstream input_file{};
    // 0-999 grid if bool to track light on/off status - initialised to off
    std::vector<std::vector<bool>> light_status{1000, std::vector<bool>(1000, false)};
    // extracted light switch action needed
    int action{};
    // extracted 4 x points for action to be applied in the grid
    std::vector<int> points{};
    // general variables
    int count_changes{};
    int lights_on{};

    // obtain count of how many lights are on
    lights_on = totalLightsOn(light_status);
    std::cout << "Initial lights on are: " << lights_on << '\n';

    // Switch comments for 'test'  vs  'final' data file
    // input_file.open("./data/day06-TEST-input.txt", std::ios::in);
    input_file.open("./data/day06-input.txt", std::ios::in);

    if (not input_file.is_open()) {
        std::cerr << "Error opening puzzle date input file. Aborted." << std::endl;
        std::exit(1);
    }

    // variables to hold input data
    std::string line{};
    int line_number{0};

    //  read each line delimited by '\n' into 'line' from the file
    while (std::getline(input_file, line)) {
        action = -1;
        points.clear();
        line_number++;
        count_changes++;

        if (debug) {
            std::cout << "\nLine number: " << line_number << " is: " << line << '\n';
        }

        // extract the switch action from the input line
        action = getSwitchAction(line);
        if (-1 == action) {
            std::cerr << "\nError: no switch action found.\n" << std::endl;
            std::exit(-1);
        }
        if (debug) {
            std::cout << "Action found is: " << action << '\n';
        }

        // extract the grid points from the input line
        points = getNumberFromString(line);
        if (debug) {
            std::cout << "Points are: ";
            for (auto point : points) {
                std::cout << point << " ";
            }
            std::cout << '\n';
        }

        // ACTIONS: 1 == toggle; 2 == on; 3 == off.
        if (action == 1) {
            LightsAsActionToggle(light_status, points);
        }
        // ACTIONS: 1 == toggle; 2 == on; 3 == off.
        if (action == 2) {
            LightsAsActionOn(light_status, points);
        }
        // ACTIONS: 1 == toggle; 2 == on; 3 == off.
        if (action == 3) {
            LightsAsActionOff(light_status, points);
        }
        if (debug) {
            std::cout << "'Lights on' are: " << totalLightsOn(light_status) << '\n';
        }
    }

    // final check of total on
    lights_on = totalLightsOn(light_status);

    std::cout << std::endl << "Advent Of Code 2015 :  Day 06 Part 01" << '\n' << '\n';
    std::cout << "  » Number of switches analysed : '" << count_changes << "'" << '\n';
    std::cout << "  » PUZZLE ANSWER: number of 'lights on' are: " << lights_on << '\n' << std::endl;

    // Part 1 Answer : 377891

    input_file.close();
    std::exit(0);
}
