class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // We do not use counting sort due to the constraints of the task (10e9 is too large)
        sort(nums.begin(), nums.end());
        for(size_t i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1])
            {
                return true;
            }
        }
        
        return false;
    }
};