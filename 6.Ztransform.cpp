#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    string convert(string s, int numRows);    
};

int main(){
    Solution so;
    string s="leetcodeishiring";
    cout<<so.convert(s,3)<<endl;
    return 0;
}

string Solution :: convert(string s,int numRows){
    string answer;
    int i=0;
    while(i<s.length()){
        answer+=s[i];
        i+=(numRows*2-2);
    }
    for(i=1;i<numRows-1;i++){
        int j=i;
        while(j<s.length()){
            answer+=s[j];
            answer+=s[j+numRows*2-2-2*i];
            j+=(numRows*2-2);
        }
    }
    i=numRows-1;
    while(i<s.length()){
        answer+=s[i];
        i+=(numRows*2-2);
    }
    return answer;
}