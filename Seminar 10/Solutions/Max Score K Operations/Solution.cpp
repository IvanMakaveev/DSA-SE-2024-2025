class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq(nums.begin(), nums.end());
        long long result = 0;
        while (k--) {
            long long topElement = pq.top();
            pq.pop();
            result += topElement;
            long long nextVal = (topElement + 2) / 3;
            pq.push(nextVal);
        }
        
        return result;
    }
};