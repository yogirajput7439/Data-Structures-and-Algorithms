## Intuition
The goal is to minimize the sum of squared differences between the two arrays. Since reducing a larger difference gives a greater reduction in its square, we should always reduce the largest differences first.

Instead of updating individual array elements, we can use a frequency array to count how many times each absolute difference occurs. This allows us to reduce the largest differences efficiently.

## Approach
1. Calculate the absolute difference at each index and store its frequency in an array.
2. Keep track of the total sum of differences and the maximum difference.
3. If the total sum of differences is less than or equal to `k1 + k2`, all differences can be reduced to zero, so return `0`.
4. Iterate from the maximum difference down to `1`. At each level, move as many differences as possible from `i` to `i - 1`, limited by the remaining operations.
5. Finally, calculate the sum of squared differences using the frequency array.

## Complexity
- **Time complexity:** \(O(n + M)\), where `n` is the array length and `M` is the maximum possible difference (100000).
- **Space complexity:** \(O(M)\), where `M` is the maximum possible difference, for the frequency array.

## Code
```cpp
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> d(100001, 0);
        long long k = (long long)k1 + k2, sum = 0;
        int mx = 0;

        // Step 1: Count the differences
        for (int i = 0; i < nums1.size(); i++) {
            int x = abs(nums1[i] - nums2[i]);
            d[x]++;
            sum += x;
            mx = max(mx, x);
        }

        // If all differences can become zero
        if (sum <= k) return 0;

        // Step 2: Reduce the largest differences first
        for (int i = mx; i > 0 && k > 0; i--) {
            long long move = min(k, (long long)d[i]);
            d[i] -= move;
            d[i - 1] += move;
            k -= move;
        }

        // Step 3: Calculate the sum of squares
        long long ans = 0;
        for (int i = 0; i <= mx; i++) {
            ans += 1LL * i * i * d[i];
        }

        return ans;
    }
};
```
