# Intuition
A binary string is beautiful if every pair of consecutive characters has the same value.

We need to check every pair. If both characters are different (`01` or `10`), exactly one change is required to make that pair beautiful.

# Approach
1. Initialize `changes = 0`.
2. Traverse the string with a step of 2.
3. Compare characters at indices `i` and `i + 1`.
4. If both characters are different, increment `changes`.
5. Return the total number of changes.

# Complexity
- **Time Complexity:** \(O(n)\) — We traverse half of the string.
- **Space Complexity:** \(O(1)\) — We use only one extra variable.

# Code

### C++ Solution
```cpp
class Solution {
public:
    int minChanges(string s) {
        int changes = 0;

        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] != s[i + 1]) {
                changes++;
            }
        }

        return changes;
    }
};
```

### Python 3 Solution
```python
class Solution:
    def minChanges(self, s: str) -> int:
        changes = 0

        for i in range(0, len(s), 2):
            if s[i] != s[i + 1]:
                changes += 1

        return changes
```
