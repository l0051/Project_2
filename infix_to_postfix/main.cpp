#include <iostream>
#include <string>
#include "lib.h"

int main()
{
    std::string infix;
    std::getline(std::cin, infix);
    infix_to_postfix(infix);
    return 0;
}
