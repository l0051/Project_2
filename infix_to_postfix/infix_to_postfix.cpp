#include <iostream>
#include <string>
#include "../lib/lib.h"

int main()
{
    std::string infix;
    std::getline(std::cin, infix);
    infix_to_postfix(infix);

    return 0;
}
