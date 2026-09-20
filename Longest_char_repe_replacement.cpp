// Longest Repeating Character Replacement — Sliding Window + Frequency Array

# Intuition

We need to find the longest substring that can be converted into a string containing the same character by replacing at most `k` characters.

For a current window:

* `windowSize` = size of the window
* `maxFreq` = frequency of the most frequent character
* `windowSize - maxFreq` = number of characters that need to be replaced

If the required replacements are greater than `k`, we shrink the window from the left.

# Approach

1. Use the **sliding window** technique with `left` and `right`.
2. Maintain the frequency of each character using a `freq` array of size `26`.
3. Update `maxFreq` whenever a character's frequency increases.
4. Calculate the number of replacements required:
   `windowSize - maxFreq`
5. If replacements are greater than `k`, move `left` forward.
6. Keep track of the maximum valid window length in `ans`.

# Complexity

* Time complexity: **O(n)**
* Space complexity: **O(1)**

# Code

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int ans = 0;
        int maxFreq = 0;

        vector<int> freq(26, 0);

        for (int right = 0; right < s.length(); right++) {

            // Add current character to the window
            freq[s[right] - 'A']++;

            // Update maximum frequency
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Current window size
            int windowSize = right - left + 1;

            // Characters that need to be replaced
            int replace = windowSize - maxFreq;

            // If replacements exceed k, shrink the window
            if (replace > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Update maximum valid window
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
```
