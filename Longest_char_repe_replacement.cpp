// Longest Repeating Character Replacement — Sliding Window + Frequency Array

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
