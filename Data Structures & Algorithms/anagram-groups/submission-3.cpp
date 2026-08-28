#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> uniqueWords;

        for (string word : strs) {
            string alphabetized = word;
            sort(alphabetized.begin(), alphabetized.end());

            if (uniqueWords.find(alphabetized) != uniqueWords.end()) {
                uniqueWords[alphabetized].push_back(word);
            }
            else {
                uniqueWords.insert({alphabetized, vector<string>({word})});
            }
        }

        vector<vector<string>> output(uniqueWords.size());

        int i = 0;
        for (pair<string, vector<string>> entry : uniqueWords) {
            output[i] = entry.second;
            ++i;
        }

        return output;
    }
};
