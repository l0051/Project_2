#include <iostream>
#include <string>
#include <stack>

bool is_operator(char symbol)
{
    return symbol == '*' || symbol == '+' || symbol == '-' || symbol == '/';
}

int priority(char current_operator)
{
    return (current_operator == '*' || current_operator == '/');
}

std::string infix_to_postfix(const std::string& infix)
{
    std::stack<char> st;
    std::string postfix;
    bool is_last_digit = false;
    for (char current : infix)
    {
        if (is_operator(current))
        {
            is_last_digit = false;
            while (!st.empty() && st.top() != '(' && priority(st.top()) >= priority(current))
            {
                postfix.push_back(' ');
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(current);
        }
        else if (current == '(')
        {
            is_last_digit = false;
            st.push(current);
        }
        else if (current == ')')
        {
            is_last_digit = false;
            while (!st.empty() && st.top() != '(')
            {
                if (!postfix.empty())
                    postfix.push_back(' ');
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if (current != ' ')
        {
            if (!is_last_digit && !postfix.empty())
                postfix.push_back(' ');
            postfix.push_back(current);
            is_last_digit = true;
        }
    }
    while (!st.empty())
    {
        postfix.push_back(' ');
        postfix.push_back(st.top());
        st.pop();
    }
    return postfix;
}

int main()
{
    std::string infix, postfix;
    std::getline(std::cin, infix);
    postfix = infix_to_postfix(infix);
    std::cout << postfix;
}
