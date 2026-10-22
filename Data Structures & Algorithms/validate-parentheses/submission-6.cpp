#include <stack>
#include <vector>
#include <string>
#include <algorithm>

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
        vector<char> openingChars = {'(', '{', '['};

        for (char c : s) {
            bool isOpeningChar = find(openingChars.begin(), openingChars.end(), c) != openingChars.end();
            if (isOpeningChar) {
                brackets.push(c);
            }
            // Closing char
            else {
                char openingChar = getOpeningChar(c);

                if (brackets.empty())
                    return false;
                char top = brackets.top();

                // Closing bracket does not match opening bracket
                if (top != openingChar)
                    return false;

                brackets.pop();
            }
        }

        return brackets.empty();
    }
};
