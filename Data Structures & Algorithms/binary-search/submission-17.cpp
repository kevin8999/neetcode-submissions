class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size();

        while (begin < end) {
            int middle = begin + (end - begin) / 2;
            int value = nums[middle];

            if (target < value) {
                end = middle;
            }
            else if (target > value) {
                begin = middle + 1;
            }
            else {
                return middle;
            }
        }

        return (begin < nums.size() && nums[begin] == target) ? begin-1 : -1;
    }
};
