##To do
##可以优化，只需要翻转一半的数字
class Solution:
    def isPalindrome(self,x:int)->bool:
        if x<0:
            return False
        ##要求不转换为字符串
        mylist=[]
        while x>0:
            mylist.append(x%10)
            x//=10
        left=0
        right=len(mylist)-1
        while left<right:
            if not mylist[right]==mylist[left]:
                return False
            right-=1
            left+=1
        return True        



if __name__=='__main__':
    so=Solution()
    print(so.isPalindrome(12321))