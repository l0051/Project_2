#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>

#include "infix_postfix.h"

int priority(const std::string& current_operator)
{
    if (current_operator == "*" || current_operator == "/" || current_operator == "%")
        return 2;
    if (current_operator == "+" || current_operator == "-")
        return 1;
    return 0;
}

bool is_operator(char symbol)
{
    std::string symbol_str = &""[symbol];
    return priority(symbol_str);
}

bool is_operator(const std::string& symbol)
{
    return priority(symbol);
}

std::vector<std::string> split(const std::string& line)
{
    std::vector<std::string> splited;
    std::string curr_elem;
    for (char current : line) {
        if (current == '(' || current == ')' || is_operator(current))
        {
            if (!curr_elem.empty())
                splited.push_back(curr_elem);
            curr_elem = "";
            curr_elem.push_back(current);
            splited.push_back(curr_elem);
            curr_elem = "";
        }
        else if (current != ' ')
        {
            curr_elem.push_back(current);
        }
        else if (!curr_elem.empty())
        {
            splited.push_back(curr_elem);
            curr_elem = "";
        }
    }
    if (!curr_elem.empty())
        splited.push_back(curr_elem);
    return splited;
}

bool is_valid_var(const std::string& operand)
{
    return std::find_if(operand.begin(), operand.end(), [](char c){return isalpha(c);}) == operand.end() ^
           std::find_if(operand.begin(), operand.end(), [](char c){return isdigit(c);}) == operand.end();
}

bool is_valid_postfix(const std::vector<std::string>& postfix)
{
    int counter = 0;
    for (const std::string& current : postfix)
    {
        if (is_valid_var(current))
            counter += 1;
        else if (is_operator(current))
            counter -= 1;
        else
            return false;
        if (counter < 1)
            return false;
    }
    return counter == 1;
}

bool is_valid_infix(const std::vector<std::string>& infix)
{
    int counter = 0;
    int par_counter = 0;
    for (const std::string& current : infix)
    {
        if (is_valid_var(current))
        {
            counter += 1;
        }
        else if (is_operator(current))
        {
            counter -= 1;
        }
        else if (current == "(")
        {
            par_counter += 1;
            if (par_counter + counter > 1)
                return false;
        }
        else if (current == ")")
        {
            par_counter -= 1;
        }
        else
        {
            return false;
        }
        if (counter < 0 || counter > 1 || par_counter < 0 || par_counter > 1)
            return false;
    }
    return counter == 1 && par_counter == 0;
}

void infix_to_postfix(const std::vector<std::string>& splited_infix)
{
    std::stack<std::string> st;
    std::string postfix;
    for (const std::string& current : splited_infix)
    {
        if (is_operator(current))
        {
            while (!st.empty() && st.top() != "(" && priority(st.top()) >= priority(current))
            {
                postfix += st.top() + " ";
                st.pop();
            }
            st.push(current);
        }
        else if (current == "(")
        {
            st.push(current);
        }
        else if (current == ")")
        {
            while (!st.empty() && st.top() != "(")
            {
                postfix += st.top() + " ";
                st.pop();
            }
            if (st.empty())
            {
                return;
            }

            st.pop();
        }
        else
        {
            postfix += current + " ";
        }
    }
    while (!st.empty())
    {
        postfix += st.top() + " ";
        st.pop();
    }
    std::cout << postfix << std::endl;
}

void postfix_to_infix(const std::vector<std::string>& splited_postfix)
{
    std::stack<std::string> st;
    std::string op;
    int last_operation_priority = 2;
    for (const std::string& current : splited_postfix)
    {
        if (is_operator(current))
        {
            op = st.top();
            st.pop();
            if (last_operation_priority < priority(current) && op.find(' ') != std::string::npos)
            {
                op = "(" + op + ")";
            }
            op = st.top() + " " + current + " " + op;
            st.pop();
            st.push(op);
            last_operation_priority = priority(current);
        }
        else
        {
            st.push(current);
        }
    }
    std::cout << st.top() << std::endl;
}

void change_infix_or_postfix(const std::string& line)
{
    std::vector<std::string> splited_line = split(line);

    if (is_valid_postfix(splited_line))
    {
        postfix_to_infix(splited_line);
    }
    else if (is_valid_infix(splited_line))
    {
        infix_to_postfix(splited_line);
    }
    else
    {
        std::cout << "Wrong input" << std::endl;
    }
}