// BRUTE FORCE APPROCH

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        vector<int> nums3;

        for(int i = 0; i < m; i++){
            nums3.push_back(nums1[i]);
        }

        for(int j = 0; j < n; j++){
            nums3.push_back(nums2[j]);
        }

        sort(nums3.begin(), nums3.end());

        int size = nums3.size();
        int mid = size / 2;

        if(size % 2 == 0){
            return (nums3[mid] + nums3[mid - 1]) / 2.0;
        }
        else{
            return nums3[mid];
        }
    }
};
