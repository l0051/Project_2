#include <iostream>
#include <string>
#include "infix_postfix.h"

int main()
{
    std::string line;
    std::getline(std::cin, line);
    change_infix_or_postfix(line);
    return 0;
}
