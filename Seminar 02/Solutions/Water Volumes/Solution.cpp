class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int max = INT_MIN;

        while(left < right) {
            int currentMax = std::min(heights[left], heights[right]) * (right - left);
            max = std::max(max, currentMax);

            if(heights[left] > heights[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        
        return max;
    }
};