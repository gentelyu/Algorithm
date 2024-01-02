#include <iostream>
#include <stack>
#include <string>



class parentheses
{
public:
    bool is_parentheses(std::string string)
    {
        std::stack<char> st;
        for(char c : string)
        {
            if(c == '(' || c == '[' || c == '{' )
            {
                st.push(c);
            }
            else if(c == ')' && !st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else if(c == ']' && !st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else if(c == '}' && !st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        return st.empty();
    }

};

int main()
{
#if 1
    std::string mystring1 = "{}[]()";
    std::string mystring2 = "{}[](";
    
    parentheses string;
    
    

    

    if(string.is_parentheses(mystring2) == false)
    {
        std::cout << "不是有效的括号" << std::endl;
    }
    else
    {
        std::cout << "是有效的括号" << std::endl;
    }

    return 0;
#else

    parentheses string;
    std::string mystring1 = "[]{}()";
    std::string mystring2 = "[()]{";

    std::cout << "字符串 " << mystring1 << " 是否是有效的括号：" << string.is_parentheses(mystring1) << std::endl;
    std::cout << "字符串 " << mystring2 << " 是否是有效的括号：" << string.is_parentheses(mystring2) << std::endl;

#endif
}