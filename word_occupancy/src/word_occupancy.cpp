#include <iostream>
#include <string>
#include <map>
#include <regex>
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