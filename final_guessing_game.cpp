// Copyright (c) 2020 Ryan Walsh All rights reserved
//
// Created by Ryan Walsh
// Created on December 7 2020
// this program checks to see if the number guessed is the magic number

#include <iostream>
#include <random>
#include <string>

int main() {
    // this program checks to see if the number guessed is the magic number
    std::string guessed_number_string;
    int random_number;
    int guessed_number;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  //  mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  //  [0,9]
    random_number = idist(rgen);


    // process and output
    while (true) {
        std::cout << "Enter a number(between 0-9)):";
        std::cin >> guessed_number_string;
        try {
            guessed_number = std::stoi(guessed_number_string);
            if (guessed_number < 0 || guessed_number > 9) {
                std::cout << "Please enter a number between 0-9";
                std::cout << "" << std::endl;
            } else if (guessed_number > random_number) {
                std::cout << "Number guessed was too high!"
                             " Try a bit lower next time";
                std::cout << "" << std::endl;
            } else if (guessed_number < random_number) {
                std::cout << "Number guessed was too low."
                             " Guess a higher number.";
                std::cout << "" << std::endl;
            } else {
                std::cout << "Congratulations! You guessed the right number!";
                std::cout << std::endl;
                break;
            }
        } catch(std::invalid_argument) {
            std::cout << "That was not a number. Please try again."
                      << std::endl;
        }
    }
}
