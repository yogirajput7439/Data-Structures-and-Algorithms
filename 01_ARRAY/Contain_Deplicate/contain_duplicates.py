class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        n = len(nums)

        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] == nums[j]:
                    return True

        return False


###############

class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        nums.sort()

        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                return True

        return False

#############

class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        return len(set(nums)) < len(nums)


##############

class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        seen = set()

        for i in nums:
            if i in seen:
                return True

            seen.add(i)

        return False

##########

class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        seen = set()
        tot = 0

        for i in nums:
            if i not in seen:
                seen.add(i)
                tot += 1

        return tot < len(nums)
