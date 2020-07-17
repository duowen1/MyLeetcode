from typing import List
class Solution:
    def maxArea(self,height:List[int]) -> int:
        left=0
        right=len(height)-1
        max_sum=0
        while left<right:
            d=right-left
            if height[left]<height[right]:
                s=d*height[left]
                max_sum=max(s,max_sum)
                left+=1
            else:
                s=d*height[right]
                right-=1
                max_sum=max(s,max_sum)
        return max_sum
            


if __name__=='__main__':
    so=Solution()
    print(so.maxArea([1,8,6,2,5,4,8,3,7]))