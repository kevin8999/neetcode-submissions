class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> string1;
        unordered_map<char, int> string2;

        for (char c : s) {
            if (string1.count(c) == 0)
                string1[c] = 1;
            else
                string1[c] += 1;
        }

        for (char c : t) {
            if (string2.count(c) == 0)
                string2[c] = 1;
            else
                string2[c] += 1;   
        }

        for (char c : s) {
            if (string1[c] != string2[c])
                return false;
        }
        for (char c : t) {
            if (string2[c] != string1[c])
                return false;
        }
        return true;
    }
};
