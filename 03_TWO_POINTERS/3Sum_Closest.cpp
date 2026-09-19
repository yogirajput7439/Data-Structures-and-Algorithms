// Time Complexity - 0(n2)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int cur_sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int new_sum = nums[i] + nums[left] + nums[right];

                if (abs(new_sum - target) < abs(cur_sum - target)) {
                    cur_sum = new_sum;
                }

                if (new_sum < target) {
                    left++;
                }
                else if (new_sum > target) {
                    right--;
                }
                else {
                    return new_sum;
                }
            }
        }

        return cur_sum;
    }
};
