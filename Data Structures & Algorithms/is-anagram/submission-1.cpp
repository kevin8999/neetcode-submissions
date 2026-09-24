class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for (char c : s) {
            if (sMap.count(c))
                sMap[c] += 1;
            else
                sMap[c] = 1;
        }

        for (char c : t) {
            if (tMap.count(c))
                tMap[c] += 1;
            else
                tMap[c] = 1;
        }

        for (char c : s) {
            if (sMap[c] != tMap[c])
                return false;
        }

        for (char c : t) {
            if (tMap[c] != sMap[c])
                return false;
        }

        return true;
    }
};
