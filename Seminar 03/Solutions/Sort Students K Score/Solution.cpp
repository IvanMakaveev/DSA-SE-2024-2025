int globalK = 0;

bool compare(vector<int>& v1, vector<int>& v2)
{
        return v1[kk] > v2[kk]; 
}

class Solution {
public:

    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        globalK = k;
        sort(score.begin(), score.end(), compare);
        return score;
    }
};