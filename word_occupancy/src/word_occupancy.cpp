#include <iostream>
#include <string>
#include <map>
#include <regex>
#include <fstream>
#include "word_occupancy.h"

void count_each_word_occupancy(const std::string& given_string)
{
    std::map<std::string, int> occupancy;
    const std::regex white_space(" ");
    std::vector<std::string> words(std::sregex_token_iterator(given_string.begin(),
                                                              given_string.end(), white_space, -1), {});
    for (std::string current_word : words)
    {
        occupancy[current_word] += 1;
    }

    for (auto it = occupancy.begin(); it != occupancy.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

void path_or_str(int argc, char **argv)
{
    if (argc == 1)
    {
        std::string given_string;
        std::getline(std::cin, given_string);
        count_each_word_occupancy(given_string);
    }
    else if (argc == 2)
    {
        std::ifstream file(argv[1]);
        if (!file)
        {
            std::cout << "Invalid argument" << std::endl;
            return;
        }
        std::string line, text;
        while(getline(file, line))
        {
            text += line;
        }
        file.close();
        count_each_word_occupancy(text);
    }
    else
    {
        std::cout << "Invalid number of arguments" << std::endl;
    }
}