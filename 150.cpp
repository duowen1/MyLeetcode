#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
    int evalRPN(vector<string>& tokens);
    int symbol(string str);    
};

int Solution :: symbol(string str){
    if(str=="+") return 1;
    if(str=="-") return 2;
    if(str=="*") return 3;
    if(str=="/") return 4;
    return 0;
}

int Solution :: evalRPN(vector<string>& tockens){
    stack<int>  mystack;
    int n=tockens.size();
    int op;
    for(int i=0;i<n;i++){
        if(op=symbol(tockens[i])){
            int right=mystack.top();
            mystack.pop();
            int left=mystack.top();
            mystack.pop();
            switch(op){
                case 1:{
                    mystack.push(left+right);
                    break;
                }
                case 2:{
                    mystack.push(left-right);
                    break;
                }
                case 3:{
                    mystack.push(left*right);
                    break;
                }
                case 4:{
                    mystack.push(left/right);
                    break;
                }
            }
        }else{
            mystack.push(stoi(tockens[i]));
        } 
    }
    return mystack.top();
}

int main(){
    Solution so;
    vector<string> tocken={"4", "13", "5", "/", "+"};
    cout<<so.evalRPN(tocken);
    return 0;
}