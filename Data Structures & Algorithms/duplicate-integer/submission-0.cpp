class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> found;

        for (auto num : nums) {
            auto it = found.find(num);
            if (it == found.end()) {
                // Duplicate not found in set
                found.insert(num);
            }
            else {
                // Duplicate found in set
                return true;
            }
        }

        return false;
    }
};