# Intuition
We can use one-dimensional Dynamic Programming (DP) to reduce space complexity. The `dp[j]` array stores the number of ways represented by the previous row at column `j`, while `res` maintains the running count for the current row. When a mirror (`1`) is encountered, we swap these states to account for the change in direction.

# Approach
1. Initialize a one-dimensional DP array of size `n` with zeros.
2. Set `dp[0] = 1` to initialize the starting position.
3. Traverse the grid row by row and column by column.
4. If the current cell contains a mirror (`1`), swap `dp[j]` and `res`.
5. Otherwise, add `dp[j]` to `res`, apply modulo, and update `dp[j]`.
6. Return the final count.

# Complexity
- **Time Complexity:** `O(m × n)`
- **Space Complexity:** `O(n)`

# Python 3
```python
class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        MOD = 1_000_000_007
        m = len(grid)
        n = len(grid[0])

        dp = [0] * n
        dp[0] = 1

        for i in range(m):
            res = 0

            for j in range(n):
                if grid[i][j] == 1:
                    dp[j], res = res, dp[j]
                else:
                    res = (res + dp[j]) % MOD
                    dp[j] = res

        return dp[n - 1]
```

# C++
```cpp
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1000000007;
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            int res = 0;

            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    swap(dp[j], res);
                } else {
                    res = (res + dp[j]) % MOD;
                    dp[j] = res;
                }
            }
        }

        return dp[n - 1];
    }
};
```
