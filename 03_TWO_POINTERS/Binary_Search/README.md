# Intuition
We need to find the target element in a sorted array. Binary Search helps us efficiently find the target by repeatedly dividing the search space into two halves.

# Approach
1. Initialize `left` and `right` pointers.
2. Calculate the middle index.
3. If `nums[mid] == target`, return `mid`.
4. If `nums[mid] < target`, search in the right half.
5. Otherwise, search in the left half.
6. If the target is not found, return `-1`.

# Complexity
- **Time Complexity:** \(O(\log n)\) — We divide the search space by half in every iteration.
- **Space Complexity:** \(O(1)\) — We use only a constant amount of extra space.

# Code

### C++ Solution
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};
```

### Python Solution
```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2

            if nums[mid] == target:
                return mid

            elif nums[mid] < target:
                left = mid + 1

            else:
                right = mid - 1

        return -1
```
