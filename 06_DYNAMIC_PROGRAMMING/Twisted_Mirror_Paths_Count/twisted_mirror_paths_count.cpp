// Optimal Solution with time complexity - O(m * n) 23ms


class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1'000'000'007;

        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);
        dp[0] = 1;

        for(int i = 0; i < m; i++){
            int res = 0;

            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    swap(res, dp[j]);
                }
                else{
                    res = (res + dp[j]) % MOD;
                    dp[j] = res;
                }
            }
        }

        return dp[n-1];

    }
};
