# Intuition

For each element in `arr1`, we need to check whether its absolute difference with every element in `arr2` is greater than `d`.

If even one element in `arr2` has an absolute difference less than or equal to `d`, the current element is not counted.

We can use a brute-force approach with two nested loops. However, we can optimize the solution by sorting `arr2` and using binary search to find whether any element exists in the range `[x - d, x + d]`.

# Approach

1. Sort `arr2` to enable binary search.
2. Iterate through each element `x` in `arr1`.
3. Use binary search to find the first element in `arr2` that is greater than or equal to `x - d`.
4. If the index is out of bounds or the element at that index is greater than `x + d`, no element exists in the range `[x - d, x + d]`.
5. In that case, increment the answer.
6. Return the final answer.

The Python solution uses `bisect_left()`, while the C++ solution uses `lower_bound()`.

# Complexity

Let `n = len(arr1)` and `m = len(arr2)`.

- Time complexity: `O(m log m + n log m)`
- Space complexity: `O(log m)` for sorting in C++ (implementation-dependent). The binary search itself uses `O(1)` auxiliary space.

# Code

### Python3

```python
from bisect import bisect_left

class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        arr2.sort()
        ans = 0

        for x in arr1:
            idx = bisect_left(arr2, x - d)

            if idx == len(arr2) or arr2[idx] > x + d:
                ans += 1

        return ans
```

### C++

```cpp
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int ans = 0;

        for (int x : arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);

            if (it == arr2.end() || *it > x + d) {
                ans++;
            }
        }

        return ans;
    }
};
```
