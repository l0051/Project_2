#include <iostream>
#include <string>
#include "lib.h"

int main()
{
    std::string postfix;
    std::getline(std::cin, postfix);
    postfix_to_infix(postfix);
    return 0;
}

