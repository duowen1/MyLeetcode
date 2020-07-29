#include <iostream>
#include <stack>
using namespace std;

class Solution{
public:
    bool isValid(string s);
};

bool Solution::isValid(string s){
    stack<char> mystack;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{') 
            mystack.push(s[i]);
        else{
            if((!mystack.empty())&&abs(mystack.top()-s[i])<3) mystack.pop();
            else return false;
        }
    }
    return mystack.empty();
}

int main(){
    string s="()[]{}";
    Solution so;
    if(so.isValid(s)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}