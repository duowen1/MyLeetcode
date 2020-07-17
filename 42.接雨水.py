from typing import List
class Solution:
    def trap_stack(self,height:List[int]) -> int:
        stack=[]
        sum=0
        for i,num in enumerate(height):
            while (not stack==[]) and (num>height[stack[-1]]):
                top=stack.pop()
                if stack==[]:
                    break
                distance=i-1-stack[-1]
                size_height=min(num,height[stack[-1]])-height[top]
                sum+=distance*size_height
            stack.append(i)
        return sum

    def trap(self, height: List[int]) -> int:
        max_layer=max(height)
        sum=0##总雨量
        for layers in range(1,max_layer+1):#分层计算可以容纳的雨水数
            for left in range(0,len(height)):
                if height[left]>=layers:
                    break
            for right in range(len(height)-1,-1,-1):
                if height[right]>=layers:
                    break
            lay=height[left:right]
            for num in lay:
                if num<layers:
                    sum+=1
        return sum 

if __name__=='__main__':
    so=Solution()
    print(so.trap_stack([0,1,0,2,1,0,1,3,2,1,2,1]))