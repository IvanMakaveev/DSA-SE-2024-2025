class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        size_t n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        int candidate1 = nums[0] * nums[1] * nums[n - 1];
        int candidate2 = nums[n - 3] * nums[n - 2] * nums[n - 1];
        
        return max(candidate1, candidate2);
    }
};