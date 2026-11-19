# LeetCode 2567. Minimum Score by Changing Two Elements

**Difficulty:** Medium

**Topics:** Array, Sorting, Greedy

---

# Approach 1: Sorting (Greedy)

## Intuition

We need to minimize the difference between the maximum and minimum elements after changing at most two elements.

The key observation is that we only need to consider three possible cases after sorting the array:

1. Change the two smallest elements.
2. Change the smallest and largest elements.
3. Change the two largest elements.

After sorting, we can calculate the minimum possible range for all three cases without actually modifying the array.

## Approach

1. Sort the array in ascending order.
2. Calculate the three possible cases:
   - `case1 = nums[n-1] - nums[2]`
   - `case2 = nums[n-2] - nums[1]`
   - `case3 = nums[n-3] - nums[0]`
3. Return the minimum among the three cases.

## Complexity

- **Time Complexity:** O(n log n) — Sorting the array.
- **Space Complexity:** O(log n) auxiliary space approximately for sorting in Python/C++ implementations.

## Python Code

```python
class Solution:
    def minimizeSum(self, nums: List[int]) -> int:

        nums.sort()

        n = len(nums)

        case1 = nums[n-1] - nums[2]
        case2 = nums[n-2] - nums[1]
        case3 = nums[n-3] - nums[0]

        return min(case1, case2, case3)
```

## C++ Code

```cpp
class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int case1 = nums[n-1] - nums[2];
        int case2 = nums[n-2] - nums[1];
        int case3 = nums[n-3] - nums[0];

        return min({case1, case2, case3});
    }
};
```

---

# Approach 2: Single Traversal (Optimized Greedy)

## Intuition

Instead of sorting the entire array, we can solve the problem using a single traversal.

We only need:
- Three largest elements.
- Three smallest elements.

We maintain these six values while traversing the array.

This allows us to avoid sorting and achieve O(n) time complexity.

## Approach

1. Initialize three largest variables with `float('-inf')`.
2. Initialize three smallest variables with `float('inf')`.
3. Traverse the array using a for loop.
4. Update the three largest and three smallest elements independently.
5. Calculate the three possible cases:

   - `case1 = largest1 - smallest3`
   - `case2 = largest2 - smallest2`
   - `case3 = largest3 - smallest1`

6. Return the minimum of these three cases.

## Complexity

- **Time Complexity:** O(n) — Only one traversal of the array.
- **Space Complexity:** O(1) — Only six variables are maintained.

## Python Code

```python
class Solution:
    def minimizeSum(self, nums: List[int]) -> int:

        largest1 = largest2 = largest3 = float('-inf')
        smallest1 = smallest2 = smallest3 = float('inf')

        for i in nums:

            # Three largest
            if i >= largest1:
                largest3 = largest2
                largest2 = largest1
                largest1 = i

            elif i >= largest2:
                largest3 = largest2
                largest2 = i

            elif i > largest3:
                largest3 = i

            # Three smallest
            if i <= smallest1:
                smallest3 = smallest2
                smallest2 = smallest1
                smallest1 = i

            elif i <= smallest2:
                smallest3 = smallest2
                smallest2 = i

            elif i < smallest3:
                smallest3 = i

        case1 = largest1 - smallest3
        case2 = largest2 - smallest2
        case3 = largest3 - smallest1

        return min(case1, case2, case3)
```

## C++ Code

```cpp
class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        int largest1 = INT_MIN;
        int largest2 = INT_MIN;
        int largest3 = INT_MIN;

        int smallest1 = INT_MAX;
        int smallest2 = INT_MAX;
        int smallest3 = INT_MAX;

        for (int i : nums) {

            // Three largest
            if (i >= largest1) {
                largest3 = largest2;
                largest2 = largest1;
                largest1 = i;
            }
            else if (i >= largest2) {
                largest3 = largest2;
                largest2 = i;
            }
            else if (i > largest3) {
                largest3 = i;
            }

            // Three smallest
            if (i <= smallest1) {
                smallest3 = smallest2;
                smallest2 = smallest1;
                smallest1 = i;
            }
            else if (i <= smallest2) {
                smallest3 = smallest2;
                smallest2 = i;
            }
            else if (i < smallest3) {
                smallest3 = i;
            }
        }

        int case1 = largest1 - smallest3;
        int case2 = largest2 - smallest2;
        int case3 = largest3 - smallest1;

        return min({case1, case2, case3});
    }
};
```

---

# Comparison of Both Approaches

| Feature | Sorting | Single Traversal |
|---|---|---|
| Technique | Sorting + Greedy | Greedy |
| Time Complexity | O(n log n) | O(n) |
| Space Complexity | O(log n) approx. | O(1) |
| Sorting Required | Yes | No |
| Traversals | Sorting operation | One traversal |
| Optimization | Good | Better |

# Important Learnings

1. Sorting helps identify the smallest and largest elements easily.
2. We don't need to actually modify the array to calculate the answer.
3. Single traversal can eliminate the need for sorting.
4. `float('inf')` and `float('-inf')` are useful in Python for initializing minimum and maximum trackers.
5. Range-based for loops (`for (int i : nums)`) are useful in C++ when indices are not required.

**Final Takeaway:** Approach 1 is easier to understand and implement. Approach 2 is the optimal O(n) solution and demonstrates stronger array-processing and greedy optimization skills.
