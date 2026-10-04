# Intuition

The brute-force approach uses four nested loops to check every possible quadruplet, which takes **O(n⁴)** time.

To optimize this, we first sort the array. Then, after fixing the first two elements, we use the **two-pointer technique** to find the remaining two elements efficiently.

Sorting also helps us handle duplicate values and ensures that the two-pointer approach works correctly.

# Approach

1. Sort the array.
2. Use the first loop to fix the first element `nums[i]`.
3. Use the second loop to fix the second element `nums[j]`.
4. Initialize two pointers:

   * `p = j + 1`
   * `q = n - 1`
5. Calculate the sum of the four elements.
6. If the sum is smaller than `target`, move `p` forward.
7. If the sum is greater than `target`, move `q` backward.
8. If the sum equals `target`, store the quadruplet in the answer and move both pointers.
9. Skip duplicate values for `i`, `j`, `p`, and `q` to avoid duplicate quadruplets.
10. Use `long long` for the sum to prevent integer overflow.

# Complexity

* Time complexity: **O(n³)**
* Space complexity: **O(1)** auxiliary space, excluding the output array.

# Code

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int p = j + 1;
                int q = n - 1;

                while (p < q) {

                    long long sum = (long long)nums[i]
                                  + nums[j]
                                  + nums[p]
                                  + nums[q];

                    if (sum < target) {
                        p++;
                    }
                    else if (sum > target) {
                        q--;
                    }
                    else {
                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[p],
                            nums[q]
                        });

                        p++;
                        q--;

                        while (p < q && nums[p] == nums[p - 1])
                            p++;

                        while (p < q && nums[q] == nums[q + 1])
                            q--;
                    }
                }
            }
        }

        return ans;
    }
};
```
