class Solution:
    def intToRoman(self,num:int)->str:
        s=''
        Roman=[['I','V'],['X','L'],['C','D'],['M']]
        Thousand=num//1000
        Hundred=(num%1000)//100
        Ten=(num%100)//10
        Inter=num%10
        if Thousand:
            s+=(Thousand*'M')
        if Hundred:
            if Hundred<=3:
                s+=(Hundred*'C')
            elif Hundred==4:
                s+='CD'
            elif Hundred<9:
                s+='D'+(Hundred-5)*'C'
            else:
                s+='CM'
        if Ten:
            if Ten<=3:
                s+='X'*Ten
            elif Ten==4:
                s+='IX'
            elif Ten<9:
                s+='L'+(Ten-5)*'X'
            else:
                s+='XC'
        if Inter:
            if Inter<=3:
                s+='I'*Inter
            elif Inter==4:
                s+='IV'
            elif Inter<9:
                s+='V'+(Inter-5)*'I'
            else:
                s+='IX'
        return s

if __name__=='__main__':
    so=Solution()
    print(so.intToRoman(1000))