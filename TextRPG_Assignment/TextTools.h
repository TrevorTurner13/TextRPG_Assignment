#pragma once


#include <iostream>
#include <sstream>
//#include <boost/lexical_cast.hpp>
/*
template <typename T> T lexical_cast(const std::string& s)
Summary of lexical_cast template function:
    lexical_cast is a reimplemenation of the same template function from the
    boost library.  It tries to convert a type to another type.
*/
template <typename T>
T lexical_cast(const std::string& s)
{
    std::stringstream ss(s);
    T result;
    if ((ss >> result).fail() || !(ss >> std::ws).eof())
    {
        throw std::bad_cast();
    }
    return result;
}
/*
int askNumber( std::string prompt, int high, int low)
Summary of the askNumber function:
    The askNumber function displays a user defined string as a prompt and gets
    input from the keyboard.  It sanitizes the input, making sure the returned
    value is an integer that is within a given range.
Parameters      : std::string prompt : containing a prompt to display
                  int high           : containing the upper limit of the range
                  int low            : containing the lower limit of the range
Return Value    : int -- the sanitized input from the keyboard
Description:
    This function uses a combination of cin::getline and boost::lexical_cast
    to guarantee the resulting input is indeed an integer, and clamps it to the
    specified range.
*/
int askNumber(std::string prompt, int high, int low) {
    std::string choiceString;
    int choice;
    bool valid;
    do {
        std::cout << prompt << " (" << low << "-" << high << "): ";
        std::getline(std::cin, choiceString);
        try {
            valid = true;
            choice = lexical_cast<int>(choiceString);
        }
        catch (const std::bad_cast&) {
            std::cout << "That's not a valid choice." << std::endl;
            valid = false;
            continue;
        }
        if (valid && (choice < low || choice > high)) {
            std::cout << "That's not a valid choice." << std::endl;
            continue;
        }
    } while (!valid || choice < low || choice > high);
    return choice;
}