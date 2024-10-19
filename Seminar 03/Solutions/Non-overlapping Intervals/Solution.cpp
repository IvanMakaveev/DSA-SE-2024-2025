bool compare(vector<int>& lhs, vector<int>& rhs)
{
    return lhs[1] < rhs[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        
        int result = 0;
        int prevEnd = intervals[0][1];

        for(size_t i = 1; i < intervals.size(); i++)
        {
            if(prevEnd > intervals[i][0])
            {
                result++;
            }
            else
            {
                prevEnd = intervals[i][1];
            }
        }
        
        return result;
    }
};