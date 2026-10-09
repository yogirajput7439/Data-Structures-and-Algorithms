# LeetCode 16 — 3Sum Closest

## Intuition

We need to find three numbers in the array whose sum is closest to the given target.

Instead of checking every possible triplet, we can optimize the solution using sorting and the two-pointer technique.

First, sort the array. Then fix one element and use two pointers to find the other two elements.

* `i` represents the fixed element.
* `left` points to the next element.
* `right` points to the last element.

Calculate the sum of these three elements and compare its distance from the target with the best sum found so far.

If the current sum is smaller than the target, move `left` forward to increase the sum.

If the current sum is greater than the target, move `right` backward to decrease the sum.

If the sum equals the target, return it immediately because no better answer is possible.

## Approach

1. Sort the array in ascending order.
2. Initialize `cur_sum` with the sum of the first three elements.
3. Iterate through the array, fixing one element at index `i`.
4. Initialize two pointers:

   * `left = i + 1`
   * `right = n - 1`
5. Calculate `new_sum = nums[i] + nums[left] + nums[right]`.
6. If the current sum is closer to the target than `cur_sum`, update `cur_sum`.
7. Adjust the pointers:

   * If `new_sum < target`, increment `left`.
   * If `new_sum > target`, decrement `right`.
   * If `new_sum == target`, return it immediately.
8. Return `cur_sum` after checking all possible fixed elements.

## Example

**Input:**

```text
nums = [-1, 2, 1, -4]
target = 1
```

After sorting:

```text
nums = [-4, -1, 1, 2]
```

The closest triplet is:

```text
-1 + 1 + 2 = 2
```

Its difference from the target is:

```text
abs(2 - 1) = 1
```

**Output:**

```text
2
```

## C++ Solution

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int cur_sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int new_sum = nums[i] + nums[left] + nums[right];

                if (abs(new_sum - target) < abs(cur_sum - target)) {
                    cur_sum = new_sum;
                }

                if (new_sum < target) {
                    left++;
                }
                else if (new_sum > target) {
                    right--;
                }
                else {
                    return new_sum;
                }
            }
        }

        return cur_sum;
    }
};
```

## Complexity Analysis

### Time Complexity

**O(n²)**

* Sorting takes O(n log n).
* The outer loop runs O(n) times.
* The inner two-pointer loop takes O(n) per iteration.

Therefore, the total time complexity is O(n²).

### Space Complexity

**O(log n)** auxiliary space typically for the sorting implementation's recursion stack, excluding implementation-dependent details.

The algorithm itself uses only a constant number of extra variables.

## Key Pattern

**Sorting + Two Pointers + Closest Sum**

This pattern is useful when:

* You need to find a pair or triplet close to a target.
* Brute force would require checking every combination.
* Sorting lets you adjust the sum efficiently by moving pointers.

## Important Observation

The key condition is:

```cpp
if (abs(new_sum - target) < abs(cur_sum - target))
```

It updates the answer only when the new sum is strictly closer to the target.

The pointer movement is based on whether the sum is smaller or greater than the target. This avoids checking every possible triplet and reduces the time complexity from O(n³) to O(n²).
