#include <iostream>
#include <stack>
#include <string>

bool is_operator(char symbol)
{
    return symbol == '*' || symbol == '+' || symbol == '-' || symbol == '/';
}

int priority(char current_operator)
{
    return (current_operator == '*' || current_operator == '/');
}

std::string postfix_to_infix(const std::string& postfix)
{
    std::stack<std::string> st;
    char last_operation_priority = 1;
    for (char current : postfix)
    {
        if (is_operator(current)) {
            std::string current_operation = st.top();
            st.pop();
//            if (last_operation_priority < priority(current))
//                current_operation = "(" + st.top() + ")" + current + current_operation;
//            else
            current_operation = st.top() + current + current_operation;
            st.pop();
            st.push(current_operation);
            last_operation_priority = priority(current);
        }
        else
        {
            st.push(std::string(1, current));
        }
    }
    if (st.empty())
        return "";
    return st.top();
}

int main()
{
    std::string infix, postfix;
    std::getline(std::cin, postfix);
    infix = postfix_to_infix(postfix);
    std::cout << infix;
}

