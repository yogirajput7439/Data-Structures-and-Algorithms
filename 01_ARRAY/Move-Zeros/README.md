# Intuition

When I first saw this problem, I immediately thought of using the **two-pointer technique** to move all zeroes to the end while maintaining the relative order of the non-zero elements.

I used two pointers:

* `st` points to the position where the next non-zero element should be placed.
* `end` searches for the next non-zero element.

When `nums[st]` is zero and `nums[end]` is non-zero, I swap them. This gradually moves all zeroes toward the end of the array.

# Approach

I decided to solve this problem using the **two-pointer technique** with constant extra space.

1. Initialize `st = 0` and `end = 1`.
2. If `nums[st]` is non-zero, move both pointers forward.
3. If both `nums[st]` and `nums[end]` are zero, move only `end` forward.
4. If `nums[st]` is zero and `nums[end]` is non-zero, swap them and move both pointers forward.
5. Continue until `end` reaches the end of the array.

# Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

# Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int st = 0;
        int end = st + 1;

        while(end < nums.size()) {
            if(nums[st] != 0) {
                st++;
                end++;
            }
            else if(nums[end] == 0) {
                end++;
            }
            else {
                swap(nums[end], nums[st]);
                st++;
                end++;
            }
        }
    }
};
```
