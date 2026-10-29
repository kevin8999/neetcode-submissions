#include <algorithm>
#include <vector>

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size()-1;
        int maxArea = -1;

        while (left < right) {
            int colHeight = min(heights[left], heights[right]);
            int width = right - left;

            int currArea = colHeight * width;
            maxArea = max(maxArea, currArea);

            if (heights[left] >= heights[right]) {
                --right;
            }
            else if (heights[left] < heights[right]) {
                ++left;
            }
        }
        return maxArea;
    }
};
