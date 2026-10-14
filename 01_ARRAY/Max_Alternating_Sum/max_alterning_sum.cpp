class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        nums.sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            while(i < n-i){
                ans += (nums[n-1-i] - nums[i]);
            }
        }

        return ans;
    }
};
