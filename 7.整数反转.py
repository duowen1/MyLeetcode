class Solution:
    def reverse(self, x: int) -> int:
        reverse=0
        flag=True
        if x<0:
            x=-1*x
            flag=False
        while not x==0:
            reverse*=10
            r=x%10
            x=x//10
            reverse+=r
        if not flag:
            reverse*=-1
        if reverse>(2**31)-1 or reverse<-1*2**31:
            reverse=0
        return reverse

if __name__=='__main__':
    so=Solution()
    print(so.reverse(125))