// Copyright (c) 2022 Aidan Lalonde-Novales All rights reserved

// Created by Aidan Lalonde-Novales
// Created on 2022-06-16
// This program formats text using a list

#include <iostream>
#include <string>
#include <list>

std::list<std::string> StringFormatter(std::list<std::string> wholeString) {
    // takes the users string and formats it
    std::list<std::string> formattedString;
    std::string headerFooter = "";
    int largestWord = 0;
    int counter;

    // find the largest word to set the width of the format
    for (auto &largeWordCheck : wholeString) {
        if (largeWordCheck.length() > largestWord) {
            largestWord = largeWordCheck.length();
        }
    }
    for (int counter = 0; counter < 4 + largestWord; counter++) {
        headerFooter.append("*");
    }

    // create the final formatted string, word by word
    formattedString.push_back(headerFooter);
    for (std::string singleWord : wholeString) {
        std::string formattedWord = "";
        while (singleWord.length() < largestWord) {
            singleWord.append(" ");
        }
        formattedWord += ("* ");
        formattedWord.append(singleWord);
        formattedWord += (" *");
        formattedString.push_back(formattedWord);
    }
    formattedString.push_back(headerFooter);

    return formattedString;
}


int main() {
    // Gets strings from the user, calls a function to format them,
    // and then outputs them back to the user
    std::string tempString;
    std::list<std::string> wholeString;
    std::list<std::string> formattedString;

    std::cout <<
    "This program takes your input and formats it to look cool.\n"
    "Enter -1 to format the strings you entered.\n"
    << std::endl;

    // input
    while (true) {
        std::cout << "Enter a line to be formatted: ";
        std::getline(std::cin, tempString);
            if (tempString != "-1") {
                wholeString.push_back(tempString);
            } else {
                std::cout << "" << std::endl;
                break;
            }
    }

    // call function
    formattedString = StringFormatter(wholeString);

    // output
    for (std::string word : formattedString) {
        std::cout << word << std::endl;
    }
    std::cout << "\nDone." << std::endl;
}
