#include <iostream>
#include <string>
#include "lib.h"

int main()
{
    std::string given_string;
    std::getline(std::cin, given_string);
    count_each_word_occupancy(given_string);
}
