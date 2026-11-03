# Solution - 1ms

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return len(nums) * max(nums) - sum(nums)



# Solution - 2ms

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        n = len(nums)
        mn = 0
        sum = 0

        for i in nums:
            if(mn < i):
                mn = i
            sum += i
        
        return mn * n - sum

# Solution - 0ms

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        mn = max(nums)
        ans = 0

        for i in nums:
            ans += mn - i
        return ans
        
