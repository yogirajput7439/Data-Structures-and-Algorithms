// Optimal Solution of O(m * n) 

class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        MOD = 1_000_000_007
        m = len(grid)
        n = len(grid[0])

        dp = [0] * n
        dp[0] = 1

        for i in range(0, m):
            res = 0

            for j in range(0, n):
                if(grid[i][j] == 1):
                    dp[j], res = res, dp[j]

                else:
                    res = (res + dp[j]) % MOD
                    dp[j] = res

        return dp[n-1]
