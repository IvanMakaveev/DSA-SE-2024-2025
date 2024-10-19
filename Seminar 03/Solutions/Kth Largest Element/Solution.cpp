class Solution {
public:
    // Example of Partition by Lomuto
    int partition(vector<int>& nums, int left, int right)
    {
        int pivot = nums[right];
        int next = left;
        for(size_t i = left; i < right; i++)
        {
            if(nums[i] > pivot)
            {
                swap(nums[i], nums[next]);
                next++;
            }
        }
        
        swap(nums[right], nums[next]);
        return next;
    }
    
    void quickSelect(vector<int>& nums, int left, int right, int k)
    {
        if (left < right)
        {
            int pivotInd = partition(nums, left, right);

            if(pivotInd == k - 1)
            {
                return;
            }
            
            if(pivotInd < k - 1)
            {
                quickSelect(nums, pivotInd + 1, right, k);
            }
            else
            {
                quickSelect(nums, left, pivotInd - 1, k);
            }
        }
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        if(nums.size() == 1)
        {
            return nums[0];
        }
        
        quickSelect(nums, 0, nums.size() - 1, k);
        
        return nums[k - 1];
    }
};