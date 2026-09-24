class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        int numZeroes = 0;

        for (int& num : nums) {
            if (num == 0) {
                ++numZeroes;
                continue;
            }
            totalProduct *= num;
        }

        if (numZeroes >= 2) {
            return vector<int>(nums.size());
        }

        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                // Handle case with one zero and zero is at i-th position
                result[i] = totalProduct;
                continue;
            }

            if (numZeroes == 1)
                result[i] = 0;
            else
                result[i] = totalProduct / nums[i];
        }

        return result;
    }
};
