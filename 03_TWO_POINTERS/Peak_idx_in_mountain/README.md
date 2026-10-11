# LeetCode 852 — Peak Index in a Mountain Array

## Intuition

A mountain array first increases and then decreases.

Our goal is to find the index of the peak element, which is the maximum element in the array.

Instead of checking every element using linear search, we can use **Binary Search** to solve the problem in O(log n) time.

The key observation is that we can compare the middle element with the next element:

- If `arr[mid] < arr[mid + 1]`, we are on the increasing slope. Therefore, the peak must be on the right side.
- Otherwise, we are on the decreasing slope or at the peak itself. Therefore, the peak is at `mid` or somewhere on the left.

By repeatedly reducing the search space, we eventually find the peak index.

## Approach

1. Initialize `left = 0` and `right = n - 1`.
2. Continue while `left < right`.
3. Calculate the middle index using:

   ```cpp
   int mid = left + (right - left) / 2;
   ```

4. Compare `arr[mid]` with `arr[mid + 1]`.
5. If `arr[mid] < arr[mid + 1]`, move `left` to `mid + 1`.
6. Otherwise, move `right` to `mid`.
7. When `left == right`, both pointers indicate the peak index.
8. Return `left`.

## Example

**Input:**

```text
arr = [0, 2, 5, 3, 1]
```

The array increases until `5` and then decreases.

```text
Index:  0  1  2  3  4
Array:  0  2  5  3  1
             ↑
           Peak
```

**Output:**

```text
2
```

The peak element is `5`, and its index is `2`.

## C++ Solution

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int left = 0;
        int right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};
```

## Complexity Analysis

### Time Complexity

**O(log n)**

In every iteration, binary search reduces the search space approximately by half.

Therefore, the total number of iterations is logarithmic in the array size.

### Space Complexity

**O(1)**

The algorithm uses only a constant number of variables and does not require additional data structures.

## Key Pattern

**Binary Search + Monotonic Slope**

This pattern is useful when an array has an increasing section followed by a decreasing section, and we need to find the peak efficiently.

## Important Observation

The condition:

```cpp
if (arr[mid] < arr[mid + 1])
```

tells us which direction to search.

- Increasing slope → move right.
- Decreasing slope or peak → keep `mid` as a possible answer.

We use `right = mid` instead of `right = mid - 1` because `mid` itself could be the peak.

Similarly, `left = mid + 1` is safe when the next element is larger, because `mid` cannot be the peak.

When both pointers meet, the peak index has been found.
