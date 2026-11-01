class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() == 2)
            return {1, 2};

        int left = 0, right = numbers.size() - 1;

        while (left != right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target)
                return {left+1, right+1};
            else if (sum > target)
                right -= 1;
            else if (sum < target)
                left += 1;
        }

        return vector<int>();
    }
};
