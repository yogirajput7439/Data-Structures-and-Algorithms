// 1ms solution 

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0;i<n; i++){
            int add = nums[n-1] - nums[i];
            nums[i] += add;
            ans += add;
            add = 0; 
        }
        return ans;
    }
};

// 0ms Solution 

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mn = 0;
        long long sum = 0;

        for(int i = 0; i < n; i++){
            if(mn < nums[i]){
                mn = nums[i];
            }
            sum += nums[i];
        }

        return n * mn - sum;
    }
};

