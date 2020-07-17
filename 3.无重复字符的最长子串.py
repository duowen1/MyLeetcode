class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        left=0
        right=1
        myset=set()
        myset.add(s[0])
        lenth=1
        max=1
        while right<len(s):
            if s[right] not in myset:#没有重复字符，窗口变长
                myset.add(s[right])
                lenth+=1
                if lenth>max:
                    max=lenth
                right+=1
            else:
                myset.remove(s[left])
                lenth-=1
                left+=1
        return max

if __name__ =='__main__':
    so=Solution()
    print(so.lengthOfLongestSubstring('pwwkew'))