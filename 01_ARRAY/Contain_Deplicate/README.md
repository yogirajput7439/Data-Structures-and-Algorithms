# Intuition
The problem asks us to determine whether any element appears more than once in the given array.

We can solve this problem using different approaches. The brute-force approach compares every pair of elements, while sorting allows us to check adjacent elements. Hashing with a set provides an efficient solution by storing previously encountered elements. We can also use a counter to track the number of unique elements.

# Approach

### Approach 1: Brute Force
Compare every element with the remaining elements in the array. If any two elements are equal, return `True`. Otherwise, return `False`.

### Approach 2: Sorting
Sort the array and check adjacent elements. If two consecutive elements are equal, a duplicate exists.

### Approach 3: Set Length
Convert the array into a set, which stores only unique elements. If the set's length is smaller than the original array's length, duplicates exist.

### Approach 4: Seen Set
Maintain a set of previously visited elements. If an element is already present in the set, return `True`. Otherwise, insert it into the set.

### Approach 5: Counter Using +=
Maintain a counter for unique elements. Whenever a new element is encountered, insert it into the set and increment the counter. If the counter becomes smaller than the original array's length, a duplicate exists.

# Complexity

Let n be the number of elements in the array.

| Approach | Time Complexity | Space Complexity |
|---|---|---|
| Brute Force | O(n²) | O(1) |
| Sorting | O(n log n) | O(1) auxiliary space for in-place sorting |
| Set Length | O(n) average | O(n) |
| Seen Set | O(n) average | O(n) |
| Counter Using += | O(n) average | O(n) |

# Code

## Python3

### 1. Brute Force
```python
class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        n = len(nums)

        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] == nums[j]:
                    return True

        return False
```

### 2. Sorting
```python
class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        nums.sort()

        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                return True

        return False
```

### 3. Set Length
```python
class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        return len(set(nums)) < len(nums)
```

### 4. Seen Set
```python
class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        seen = set()

        for i in nums:
            if i in seen:
                return True

            seen.add(i)

        return False
```

### 5. Counter Using +=
```python
class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        seen = set()
        tot = 0

        for i in nums:
            if i not in seen:
                seen.add(i)
                tot += 1

        return tot < len(nums)
```

## C++

### 1. Brute Force
```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};
```

### 2. Sorting
```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }
};
```

### 3. Set Length
```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        return s.size() < nums.size();
    }
};
```

### 4. Seen Set
```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int i : nums) {
            if (seen.count(i)) {
                return true;
            }

            seen.insert(i);
        }

        return false;
    }
};
```

### 5. Counter Using +=
```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        int tot = 0;

        for (int i : nums) {
            if (seen.insert(i).second) {
                tot += 1;
            }
        }

        return tot < nums.size();
    }
};
```
