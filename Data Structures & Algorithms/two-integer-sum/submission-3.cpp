class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Key = difference. Value = index.
        unordered_map<int, int> map;

        int i = 0;
        for (int num : nums) {
            int diff = target - num;

            if (map.find(diff) != map.end()) {
                vector<int> result{map[diff], i};
                return result;
            }
            map[num] = i;
            i++;
        }
        
        return vector<int>();
    }
};
