from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dict={}
        for i in range(0,len(nums)):
            if (target-nums[i]) in dict:
                return (dict[target-nums[i]],i)
            if nums[i] not in dict:
                dict[nums[i]]=i

if __name__=='__main__':
    so=Solution()
    print(so.twoSum([1,2,3,4,6],5))