# Intuition

We need to find the minimum sum of a path from the top-left cell to the bottom-right cell of a grid. We can only move right or down.

At each cell, we can reach it either from the top or from the left. Therefore, we choose the minimum cost between these two possible paths and add the current cell's value.

To optimize space, we use a 1D DP array instead of a 2D DP matrix. The array stores the minimum path sums for the current row as we iterate through the grid.

# Approach

1. Initialize a 1D DP array of size `n`, where `n` is the number of columns.
2. Set `dp[0]` to the value of the top-left cell.
3. Initialize the first row by adding each cell's value to the previous DP value.
4. For each subsequent row:
   - Update `dp[0]` by adding the current cell's value because we can only move down in the first column.
   - For every remaining column, update the DP value by adding the current grid cell's value to the minimum of the value from above (`dp[j]`) and the value from the left (`dp[j - 1]`).
5. Return `dp[n - 1]`, which contains the minimum path sum to the bottom-right cell.

# Complexity

- Time complexity: $$O(m \times n)$$

  We visit each cell of the grid once.

- Space complexity: $$O(n)$$

  We use a 1D DP array of size `n`, where `n` is the number of columns.

# Code

## C++ — 1D Dynamic Programming

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);
        dp[0] = grid[0][0];

        // Initialize the first row
        for (int j = 1; j < n; j++) {
            dp[j] = grid[0][j] + dp[j - 1];
        }

        // Process the remaining rows
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];

            for (int j = 1; j < n; j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];
    }
};
```

## Python — 1D Dynamic Programming

```python
class Solution:
    def minPathSum(self, grid: list[list[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        dp = [0] * n
        dp[0] = grid[0][0]

        # Initialize the first row
        for j in range(1, n):
            dp[j] = grid[0][j] + dp[j - 1]

        # Process the remaining rows
        for i in range(1, m):
            dp[0] += grid[i][0]

            for j in range(1, n):
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1])

        return dp[n - 1]
```
