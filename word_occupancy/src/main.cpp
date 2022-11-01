#include <iostream>
#include <string>
#include "word_occupancy.h"

int main()
{
    std::string given_string;
    std::getline(std::cin, given_string);
    count_each_word_occupancy(given_string);
}
