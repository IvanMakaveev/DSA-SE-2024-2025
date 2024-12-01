// 09. Matrix Chain Multiplication
/// Table - triangular table!!!!
/// [i][j] = min multiplications from i-th to j-th matrix
/// Rec: [i][j] = min(for every k: d[i][k] + d[k+1][j] + d[i]*d[k]*d[j])
int solve(vector<int> arr)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            dp[i][j] = INT_MAX;

            for (int k = i + 1; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + arr[i] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1];
}