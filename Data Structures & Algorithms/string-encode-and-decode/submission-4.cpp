class Solution {
public:
    // Takes up 3 bytes
    const string delimiter = "大";

    string encode(vector<string>& strs) {
        string result = "";

        for (string& word : strs) {
            int len = word.length();

            result += to_string(len);
            result += delimiter;
            result += word;
        }

        cout << result << "\n";

        return result;
    }

    vector<string> decode(string& s) {
        vector<string> result;

        int i = 0;
        for (int j = 0; j < s.length();) {
            char c = s[j];

            string numString;
            while (isdigit(c)) {
                c = s[j];

                if (!isdigit(c))
                    break;

                numString += c;
                ++j;
            }

            cout << "numString: " << numString<< "\n";

            // Convert to number
            int num = std::stoi(numString);
            cout << num << "\n";

            // Skip over delimiter
            j += 3;
            cout << "s[j]: " << s[j] << "\n";

            // Push string to result
            result.push_back("");
            for (int k = 0; k < num; ++k) {
                char stringChar = s[j + k];
                result[i].push_back(stringChar);
            }

            i += 1;
            j += num;
        }

        return result;
    }
};
