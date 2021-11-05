// Copyright (c) 2021 Igor All rights reserved
//
// Created by: Igor
// Created on: Nov 2021
// This program uses an associative array

#include <string.h>
#include <string>
#include <iostream>
#include <list>
#include <map>

void hexx(std::string dictionary1,
std::list<std::string> &hex1) {
    std::list<std::string> letterList;
    std::string space = " ";
    size_t pos = 0;
    std::string letter;
    std::string letter1;
    std::map<std::string, std::string> dictionary;

    // Adding Items
    dictionary[" "] = "0x20";
    dictionary["!"] = "0x21";
    // Can't Add in 22 since it is a Quotation Mark (")
    dictionary["#"] = "0x23";
    dictionary["$"] = "0x24";
    dictionary["%"] = "0x25";
    dictionary["&"] = "0x26";
    dictionary["'"] = "0x27";
    dictionary["("] = "0x28";
    dictionary[")"] = "0x29";
    dictionary["*"] = "0x2a";
    dictionary["+"] = "0x2b";
    dictionary[","] = "0x2c";
    dictionary["-"] = "0x2d";
    dictionary["."] = "0x2e";
    dictionary["/"] = "0x2f";
    dictionary["0"] = "0x30";
    dictionary["1"] = "0x31";
    dictionary["2"] = "0x32";
    dictionary["3"] = "0x33";
    dictionary["4"] = "0x34";
    dictionary["5"] = "0x35";
    dictionary["6"] = "0x36";
    dictionary["7"] = "0x37";
    dictionary["8"] = "0x38";
    dictionary["9"] = "0x39";
    dictionary[":"] = "0x3a";
    dictionary[";"] = "0x3b";
    dictionary["<"] = "0x3c";
    dictionary["="] = "0x3d";
    dictionary[">"] = "0x3e";
    dictionary["?"] = "0x3f";
    dictionary["@"] = "0x40";
    dictionary["A"] = "0x41";
    dictionary["B"] = "0x42";
    dictionary["C"] = "0x43";
    dictionary["D"] = "0x44";
    dictionary["E"] = "0x45";
    dictionary["F"] = "0x46";
    dictionary["G"] = "0x47";
    dictionary["H"] = "0x48";
    dictionary["I"] = "0x49";
    dictionary["J"] = "0x4a";
    dictionary["K"] = "0x4b";
    dictionary["L"] = "0x4c";
    dictionary["M"] = "0x4d";
    dictionary["N"] = "0x4e";
    dictionary["O"] = "0x4f";
    dictionary["P"] = "0x50";
    dictionary["Q"] = "0x51";
    dictionary["R"] = "0x52";
    dictionary["S"] = "0x53";
    dictionary["T"] = "0x54";
    dictionary["U"] = "0x55";
    dictionary["V"] = "0x56";
    dictionary["W"] = "0x57";
    dictionary["X"] = "0x58";
    dictionary["Y"] = "0x59";
    dictionary["Z"] = "0x5a";
    dictionary["["] = "0x5b";  //  Can't Add in 5c since it is a Backslash (\)
    dictionary["]"] = "0x5d";
    dictionary["^"] = "0x5e";
    dictionary["_"] = "0x5f";
    dictionary["`"] = "0x60";
    dictionary["a"] = "0x61";
    dictionary["b"] = "0x62";
    dictionary["c"] = "0x63";
    dictionary["d"] = "0x64";
    dictionary["e"] = "0x65";
    dictionary["f"] = "0x66";
    dictionary["g"] = "0x67";
    dictionary["h"] = "0x68";
    dictionary["i"] = "0x69";
    dictionary["j"] = "0x6a";
    dictionary["k"] = "0x6b";
    dictionary["l"] = "0x6c";
    dictionary["m"] = "0x6d";
    dictionary["n"] = "0x6e";
    dictionary["o"] = "0x6f";
    dictionary["p"] = "0x70";
    dictionary["q"] = "0x71";
    dictionary["r"] = "0x72";
    dictionary["s"] = "0x73";
    dictionary["t"] = "0x74";
    dictionary["u"] = "0x75";
    dictionary["v"] = "0x76";
    dictionary["w"] = "0x77";
    dictionary["x"] = "0x78";
    dictionary["y"] = "0x79";
    dictionary["z"] = "0x7a";
    dictionary["{"] = "0x7b";
    dictionary["|"] = "0x7c";
    dictionary["}"] = "0x7d";
    dictionary["~"] = "0x7e";


    while ((pos = dictionary1.find(space)) != std::string::npos) {
        letter = dictionary1.substr(0, pos);
        letterList.push_back(letter);
        dictionary1.erase(0, pos + space.length());
    }
    for (auto &letter1 : letterList) {
        char arr[letter1.length()];
        int iter;
        strcpy(arr, letter1.c_str());

        for (int iter = 0; iter < letter1.length(); iter++) {
            std::string key = std::string(1, arr[iter]);
            auto itr = dictionary.find(key);
            if (itr != dictionary.end()) {
                hex1.push_back(itr->second);
            }
        }
    }
}
int main() {
    // input
    std::list<std::string> hex1;
    std::string dictionary1 = "";

    std::cout << "Starting..." << std::endl;

    std::cout << "" << std::endl;
    std::cout << "Please enter a string to be translated into hex: ";
    std::getline(std::cin, dictionary1);

    std::cout << "" << std::endl;

    // output
    dictionary1.append(" ");
    hexx(dictionary1, hex1);
    std::cout << dictionary1 << "in hex is ['";
    for (auto hexLetter : hex1) {
        std::cout << "'" << hexLetter << "' ";
    }
    std::cout << "]" << std::endl;

    std::cout << "" << std::endl;
    std::cout << "Done." << std::endl;
}
