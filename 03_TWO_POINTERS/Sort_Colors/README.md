# LeetCode 75 — Sort Colors

## Intuition

We are given an array containing only three values: `0`, `1`, and `2`.

We need to sort the array in-place so that all `0`s come first, followed by all `1`s, and then all `2`s.

Instead of using a sorting algorithm such as `sort()`, we can solve this problem in one traversal using three pointers.

This approach is known as the **Dutch National Flag Algorithm**.

We divide the array into four regions:

* `0` to `low - 1`: Contains only `0`s.
* `low` to `mid - 1`: Contains only `1`s.
* `mid` to `high`: Contains unclassified elements.
* `high + 1` to the end: Contains only `2`s.

The algorithm processes the unclassified region until `mid > high`.

## Approach

1. Initialize three pointers:

   * `low = 0`
   * `mid = 0`
   * `high = nums.size() - 1`
2. Traverse the array while `mid <= high`.
3. If `nums[mid] == 0`:

   * Swap `nums[low]` and `nums[mid]`.
   * Increment both `low` and `mid`.
4. If `nums[mid] == 1`:

   * Increment `mid` because `1` is already in the correct region.
5. If `nums[mid] == 2`:

   * Swap `nums[mid]` and `nums[high]`.
   * Decrement `high`.
   * Do not increment `mid`, because the swapped element has not been checked yet.
6. Return the sorted array by modifying it in-place.

## Example

**Input:**

```text
nums = [2, 0, 2, 1, 1, 0]
```

**Step 1:** `nums[mid] = 2`

Swap the middle element with the element at `high`.

```text
[0, 0, 2, 1, 1, 2]
```

**Step 2:** Process the `0`s and `1`s using the three pointers.

After all iterations:

```text
[0, 0, 1, 1, 2, 2]
```

**Output:**

```text
[0, 0, 1, 1, 2, 2]
```

## C++ Solution

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
```

## Complexity Analysis

### Time Complexity

**O(n)**

Each iteration processes an element, and the pointers move only forward or backward through the array. Therefore, the array is sorted in a single pass.

### Space Complexity

**O(1)**

The algorithm uses only three pointers and performs swaps in-place. No additional array is required.

## Key Pattern

**Three Pointers + In-Place Sorting + Dutch National Flag Algorithm**

This pattern is useful when an array contains three distinct categories that must be grouped in a specific order.

## Important Observation

The most important part of this algorithm is:

```cpp
else {
    swap(nums[mid], nums[high]);
    high--;
}
```

We do not increment `mid` here because the element swapped from the `high` position is still unclassified. We must inspect it before moving forward.

If we incremented `mid` immediately, we could skip an element that needs to be moved to another region.

The algorithm achieves O(n) time and O(1) auxiliary space, making it more efficient than comparison-based sorting for this specific problem.
