class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void backtrack(int index, vector<int>& nums) {
        ans.push_back(subset);

        for (int i = index; i < nums.size(); i++) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1])
                continue;

            subset.push_back(nums[i]);
            backtrack(i + 1, nums);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(0, nums);
        return ans;
    }
};
