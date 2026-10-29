#include <unordered_set>
#include <list>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> found(nums.begin(), nums.end());
        int longest = 0;

        for (int n : nums) {
            if (!found.contains(n-1)) {
                int next = n;
                while (found.contains(next)) {
                    ++next;
                }
                int sequenceLength = next - n;
                longest = max(longest, sequenceLength);
            }
        }

        return longest;
    }
};
