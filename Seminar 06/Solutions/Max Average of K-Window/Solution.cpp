class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        queue<int> q;
        int maxSum = 0;
        for(int i = 0; i < k; i++)
        {
            q.push(nums[i]);
            maxSum += nums[i];
        }

        int currSum = maxSum;
        for(int i = k; i < nums.size(); i++)
        {
            currSum += nums[i] - q.front();
            q.pop();
            q.push(nums[i]);

            if(currSum > maxSum)
            {
                maxSum = currSum;
            }
        }

        return (maxSum * 1.0) / k;
    }
};