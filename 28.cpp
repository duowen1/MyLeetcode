#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution{
public:
    int strstr(string haystack,string needle);
};

int Solution::strstr(string haystack,string needle){
    //算了，直接调用库函数吧，研究什么KMP算法
    if(needle.empty()) return 0;
    return haystack.find(needle);
}

int main(){
    string haystack="hello";
    string needle="ll";
    Solution so;
    cout<<so.strstr(haystack,needle)<<endl;
    return 0;
}