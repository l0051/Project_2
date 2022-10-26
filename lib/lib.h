#ifndef INFIX_TO_POSTFIX_LIB_H
#define INFIX_TO_POSTFIX_LIB_H

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>

int priority(const std::string& current_operator);

bool is_operator(char symbol);

bool is_operator(const std::string& symbol);

std::vector<std::string> split(const std::string& line);

bool is_valid_var(const std::string& operand);

bool is_valid_postfix(const std::vector<std::string>& postfix);

bool is_valid_infix(const std::vector<std::string>& infix);

std::string infix_to_postfix_util(const std::vector<std::string>& splited_infix);

std::string splited_to_line(const std::vector<std::string>& splited);

void infix_to_postfix(const std::string& infix);

#endif //INFIX_TO_POSTFIX_LIB_H
