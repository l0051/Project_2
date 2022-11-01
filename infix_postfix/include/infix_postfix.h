#ifndef PROJECT_1_INFIX_POSTFIX_H
#define PROJECT_1_INFIX_POSTFIX_H

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>
#include <regex>

int priority(const std::string& current_operator);

bool is_operator(char symbol);

bool is_operator(const std::string& symbol);

std::vector<std::string> split(const std::string& line);

bool is_valid_var(const std::string& operand);

bool is_valid_postfix(const std::vector<std::string>& postfix);

bool is_valid_infix(const std::vector<std::string>& infix);

void infix_to_postfix(const std::vector<std::string>& splited_infix);

void postfix_to_infix(const std::vector<std::string>& splited_postfix);

void change_infix_or_postfix(const std::string& line);

#endif
