// 02 - Binomials
//// Таблица [n][k] = n choose k
//// Уравнение: (N K) = (N-1 K-1) + (N-1 K)
// Top-down
int getnCk(int n, int k, vector<vector<int>> &memo) {
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    
    if(memo[n][k] != -1) return memo[n][k];
  
    return memo[n][k] = getnCk(n - 1, k - 1, memo) + getnCk(n - 1, k, memo);
}

int binomialCoeff(int n, int k) {
    vector<vector<int>> memo(n + 1, vector<int> (k + 1, -1));
    return getnCk(n, k, memo);
}

int main() {
    int n = 5, k = 2;
    cout << binomialCoeff(n, k);
    return 0;
}

////////////////////
// Bottom-up

int binomialCoeff(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int> (k + 1));
  
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
          
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}