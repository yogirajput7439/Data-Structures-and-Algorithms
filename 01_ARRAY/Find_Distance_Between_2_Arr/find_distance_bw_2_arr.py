class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        ans = 0

        for i in arr1:
            count = 0
            for j in arr2:
                if (abs(i - j) > d):
                    count+=1
                else:
                    break
    

            if(count == len(arr2)):
                ans+=1
    
        return ans
