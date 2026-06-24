// Best Solution 

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            ans ^= i ^ nums[i];
        }

        return ans;
    }
};

// Optimal Solution 

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        long long expected = 1LL * n * (n + 1) / 2;
        long long actual = 0;

        for (int num : nums) {
            actual += num;
        }

        return expected - actual;
    }
};
