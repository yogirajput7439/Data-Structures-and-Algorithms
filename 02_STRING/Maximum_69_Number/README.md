# Intuition
The goal is to maximize the given number by changing at most one digit from `6` to `9`.

To get the maximum possible number, we should replace the **leftmost occurrence of `6`** with `9`, because the leftmost digit has the highest place value.

# Approach
1. Convert the integer into a string.
2. Find the first occurrence of `6`.
3. Replace only that occurrence with `9`.
4. Convert the modified string back into an integer.
5. If no `6` exists, return the original number.

# Complexity
- **Time Complexity:** \(O(d)\), where d is the number of digits.
- **Space Complexity:** \(O(d)\), for storing the string.

# Code

### Python 3 (Optimal)
```python
class Solution:
    def maximum69Number(self, num: int) -> int:
        return int(str(num).replace('6', '9', 1))
```

### C++ (Optimal)
```cpp
class Solution {
public:
    int maximum69Number(int num) {
        std::string s = std::to_string(num);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '6') {
                s[i] = '9';
                break;
            }
        }

        return std::stoi(s);
    }
};
```
