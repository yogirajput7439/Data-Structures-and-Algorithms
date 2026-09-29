class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int st = 0;
        int end = st+1;

        while(end < nums.size()){
            if(nums[st] != 0){
                st++;
                end++;
            }
            else if(nums[end] == 0){
                end++;
            }
            else{
                swap(nums[end], nums[st]);
                st++;
                end++;
            }
        }
    }
};
