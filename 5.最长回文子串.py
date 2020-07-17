class Solution:
    def longestPalindrome(self, s: str) -> str:
        #动态规划法解
        #时间复杂度O(n^2)
        #空间复杂度O(n^2)
        #构造一个n*n的矩阵，矩阵元素(i,j)表示s[i:j]是否为回文数
        #显然(i,i)=True，(i,j)j<i时为false
        #对于(i,i+1),当且仅当s[i]==s[i+1]时为True
        #对于(i,j),当且仅当(i+1,j-1)为True且s[i]==s[j]时为False
        n=len(s)
        answer=""
        A=[[False]*n for _ in range(0,n)]#利用列表生成式生成一个n*n的矩阵
        for l in range(0,n):#子串的长度为l+1
            for i in range(0,n):#起始点，必须遍历起始点
                j=i+l#终止点
                if j>=n:#下标越界
                    break
                if l==0:
                    A[i][j]=True
                elif l==1:
                    A[i][j]=(s[i]==s[j])
                else:
                    A[i][j]=(A[i+1][j-1]) and (s[i]==s[j])
                if A[i][j] and l+1>len(answer):
                    answer=s[i:j+1]
        for i in range(0,n):
            print(A[i])
        return answer

    def expandAroundCenter(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:#下标不越界且扩展的相等
            left -= 1
            right += 1
        return left + 1, right - 1

    def longestPalindrome2(self, s: str) -> str:
        #中心拓展法
        start, end = 0, 0
        for i in range(len(s)):
            left1, right1 = self.expandAroundCenter(s, i, i)#边界条件串长为1
            left2, right2 = self.expandAroundCenter(s, i, i + 1)#边界条件串长为2
            if right1 - left1 > end - start:
                start, end = left1, right1
            if right2 - left2 > end - start:
                start, end = left2, right2
        return s[start: end + 1]

if __name__ =='__main__':
    so=Solution()
    print(so.longestPalindrome('cbbad'))