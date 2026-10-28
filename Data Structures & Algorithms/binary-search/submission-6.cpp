class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            bool equals = nums[0] == target;
            if (equals)
                return 0;
            else
                return -1;
        }

        int begin = 0;
        int end = nums.size();

        while (begin != end) {
            int middle = begin + ((end - begin) / 2);
            int value = nums[middle];

            if (begin == end) {
                if (nums[middle] == target)
                    return middle;
                else
                    return -1;
            }

            if (end - begin == 2) {
                if (nums[begin] == target)
                    return begin;
                else if (nums[end-1] == target)
                    return end-1;
                else
                    return -1;
            }

            if (target < value) {
                end = middle;
                continue;
            }
            else if (target > value) {
                begin = middle;
                continue;
            }
            else if (target == value) {
                return middle;
            }
        }

        return -1;
    }
};
