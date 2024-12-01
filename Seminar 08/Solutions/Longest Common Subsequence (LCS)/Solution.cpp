// 08. Longest Common Subsequence
//// Table - [n][m] = longest subsequence of text1[n] text2[m]
//// Rec - [n][m] = if curr1[n] == curr2[m]: [n-1][m-1] + 1
////                else max([n-1][m], [n][m-1])
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        
        for(size_t i = 0; i < text1.size(); i++) {
            for(size_t j = 0; j < text2.size(); j++) {
                if(text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        
        return dp[text1.size()][text2.size()];
    }
};