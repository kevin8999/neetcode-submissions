#include <set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> found;

        for (int num : nums) {
            if (found.contains(num))
                return true;
            
            found.insert(num);
        }

        return false;
    }
};