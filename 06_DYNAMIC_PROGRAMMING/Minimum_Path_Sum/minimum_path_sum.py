# Solution in 2D Array

class Solution:
    def minPathSum(self, grid: list[list[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        dp = [[0] * n for _ in range(m)]

        dp[0][0] = grid[0][0]

        for j in range(1, n):
            dp[0][j] = grid[0][j] + dp[0][j-1]

        for i in range(1, m):
            dp[i][0] = grid[i][0] + dp[i-1][0]
        
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])

        return dp[m-1][n-1]


# Solution in 1D Array

class Solution:
    def minPathSum(self, grid: list[list[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        dp = [0] * n

        dp[0] = grid[0][0]

        for j in range(1, n):
            dp[j] = grid[0][j] + dp[j-1]

        for i in range(1, m):
            
            dp[0] += grid[i][0]
            
            for j in range(1, n):
                dp[j] = grid[i][j] + min(dp[j], dp[j-1])

        
        return dp[n-1]
