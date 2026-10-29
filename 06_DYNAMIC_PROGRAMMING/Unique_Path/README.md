## Intuition

The robot can move only right or down. To reach any cell, it must come either from the cell above or from the cell on the left.

Therefore, the number of unique paths to a cell is the sum of the paths to these two neighboring cells.

Instead of using a 2D DP table, we can optimize space by maintaining a single 1D array.

## Approach

1. Initialize a 1D DP array of size `n` with all elements set to `1`, since there is exactly one way to reach each cell in the first row.
2. Iterate through the remaining rows.
3. For each row, start iterating from the second column.
4. Update each element using `dp[j] = dp[j] + dp[j - 1]`.
   - `dp[j]` represents the number of paths from above.
   - `dp[j - 1]` represents the number of paths from the left.
5. Return `dp[n - 1]`, which contains the total number of unique paths to the destination.

The same approach works in both Python3 and C++.

## Complexity

- **Time Complexity:** $$O(m \times n)$$
- **Space Complexity:** $$O(n)$$

## Code — Python3

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [1] * n

        for i in range(1, m):
            for j in range(1, n):
                dp[j] = dp[j] + dp[j - 1]

        return dp[n - 1]
```

## Code — C++

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};
```
