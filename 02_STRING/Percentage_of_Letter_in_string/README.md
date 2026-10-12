## Intuition
Count how many times `letter` appears in the string `s`. Then calculate its percentage using the total length of the string.

## Approach
1. Initialize `count` to `0`.
2. Traverse the string and increment `count` whenever a character matches `letter`.
3. Calculate the percentage using `(count * 100) / s.length()`.
4. Return the calculated percentage.

## Complexity
- **Time Complexity:** O(n), where `n` is the length of the string.
- **Space Complexity:** O(1), as only a constant amount of extra space is used.

## Code
```cpp
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        int ans = 0;

        for (char x : s) {
            if (x == letter) {
                count += 1;
            }
        }

        ans = (count * 100) / s.length();

        return ans;
    }
};
```
