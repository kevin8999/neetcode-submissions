#include <stack>
#include <string>

class Solution {
public:
    char getOpeningChar(char c) {
        switch (c) {
            case ')':  return '(';
            case '}':  return '{';
            case ']':  return '[';
            default:   return ' ';
        }
    }

    bool isValid(string s) {
        if (s.length() % 2 == 1)
            return false;

        stack<char> brackets;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                brackets.push(c);
            }
            else if (c == ')' || c == '}' || c == ']') {
                if (brackets.empty() || getOpeningChar(c) != brackets.top())
                    return false;
                brackets.pop();
            }
        }

        return brackets.empty();
    }
};
