#!/usr/bin/env -S deno run --quiet --allow-read=./
/**
 * @file aoc_day01_p2.ts
 * @brief Advent of Code (AOC) 2015 Puzzle solution for:  Day 01 Part 2.
 *
 * @author simon rowe <simon@wiremoons.com>
 * @license open-source released under "MIT License"
 *
 * @date originally created: 14 March 2021
 *
 * @details Advent of Code (AOC) 2015 Puzzle solution. See: https://adventofcode.com/2015/
 *
 * @note The program can be run with Deno using the command:
 * @code deno run --quiet --allow-read ./aoc_day01_p2.ts
 */

//--------------------------------
// MODULE IMPORTS
//--------------------------------
// import modules to support program:
import { existsFile } from "https://deno.land/x/deno_mod@0.8.1/mod.ts";

//--------------------------------
// MAIN
//--------------------------------
if (import.meta.main) {
  //********************************
  // APPLICATION CONFIGURATION
  //********************************
  // define the base location for Deno application directories:
  const aocDay = "01";
  const aocPart = "02";

  // SET INPUT PUZZLE DATA FILE NAME:
  // Puzzle data:
  const inputFile = `./data/day${aocDay}-input.txt`;
  // Puzzle data 'TEST':
  //const inputFile = `./data/day${aocDay}-TEST-input.txt`;
  //********************************

  // Display startup message
  console.log(`\nAdvent Of Code 2015 :  Day ${aocDay} Part ${aocPart}\n`);

  // Ensure the 'puzzle input' file can be found and loaded

  if (!await existsFile(inputFile)) {
    console.error(
      `\nERROR: failed to find the puzzle input file: '${inputFile}'. Exit.\n`,
    );
    Deno.exit(1);
  }

  // set up tracking counters
  let up = 0;
  let down = 0;
  let floor = 0;
  let firstbasement = 0;

  // Read in the puzzle data
  const puzzleData = await Deno.readTextFile(inputFile);
  // read puzzle data into lines of text

  [...puzzleData].forEach((c) => {
    c === "(" ? up++ && floor++ : down++ && floor--;
    if (floor === -1 && firstbasement === 0) firstbasement = up + down;
  });

  console.log(` » Moved up '${up}' floors and down '${down}' floors`);
  console.log(` » Floor changes analysed: ${up + down}`);
  console.log(
    ` » PUZZLE ANSWER: Basement first reached floor move : ${firstbasement}\n`,
  );
  console.log("DONE");
}
