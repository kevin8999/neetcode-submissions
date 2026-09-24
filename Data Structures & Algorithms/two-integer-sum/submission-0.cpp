class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> differences;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int difference = target - num;

            // If difference is in differences hashmap
            if (differences.count(difference)) {
                int differenceIndex = differences[difference];
                int numIndex = i;

                vector<int> sums = {differenceIndex, numIndex};
                return sums;
            }
            else {
                // Store index
                differences[num] = i;
            }
        }
        return vector<int>();
    }
};
