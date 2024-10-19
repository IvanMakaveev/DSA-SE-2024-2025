class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        
        int first = 0, second = 0;
        while(first < nums1.size() && second < nums2.size())
        {
            if(nums1[first] < nums2[second])
            {
                first++;
            }
            else if(nums1[first] > nums2[second])
            {
                second++;
            }
            else
            {
                result.push_back(nums1[first]);
                first++;
                second++;
            }
        }
        
        return result;
    }
};