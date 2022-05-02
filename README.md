# CPPND: Capstone Snake Game Example
This repo has committed the extsion codes for Capstone project in the  [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl). The extension includes:
1. A LeaderBoard class that add, reset, and display scores from players (idea is inspired by [leader board question](https://leetcode.com/problems/design-a-leaderboard/)). 
2. A SimpleData class that read and write LeaderBoard data from a file. 

## Class Structure

## Expected Behavior
1. Enter your player ID. If your player ID does not exist, the system will generate a new (unique) ID for you. <img src="https://github.com/shijingl/CppND-Capstone-Snake-Game/blob/master/Step-1.png"/>
2. Play the Snake Game as before.
3. Your score will be updated in leader board and be written into files. 

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Rubric Points Match
#### <br>1. The project reads data from an external file or writes data to a file as part of the necessary operation of the program. </br>
The entire SimpleData class is designed and implemented for handling read/write data from files. Please see SimpleData.h, SimpleData.cpp.
#### <br>2. The project accepts input from a user as part of the necessary operation of the program.</br>
The project ask users to enter their player ID. Please see line 21 to 22 in main.cpp.
#### <br>3. Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.</br>
The entire LeaderBoard class are designed to satisfy this criteria. Please see LeaderBoard.h, LeaderBoard.cpp.
#### <br>4. One function is declared with a template that allows it to accept a generic parameter.</br>
For example, line 4 to line 13 in LeaderBoard.cpp, and line 15 to line 24 in SimpleData.h.
#### <br>5. A variety of control structures are used in the project. The project code is clearly organized into functions.</br>
For example, line 41~line 62 in LeaderBoard.cpp, for loop and if statement is used. All project codes is clearly organized into functions.
#### <br>6. The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.</br>
This applies to the entire codebase in the repo.
#### <br>7. All class data members are explicitly specified as public, protected, or private.</br>
Yes. Specifically, an example is LeaderBoard class. private members can only be mutated by the member functions inside class. Outside functions can only get the data from private members through the public getter functions. 

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
