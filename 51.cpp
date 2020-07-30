#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution{
private:
    int N;
    vector<bool> columns;//当前列是否可以放置
    vector<bool> left_diagonals;//左向对角线是否可以放置
    vector<bool> right_diagonals;//右向对角线是否可以放置
    set<pair<int,int>> qipan;//保存皇后的位置
    vector<vector<string>> answers;//最后的结果


public:
    vector<vector<string>> solveNQueens(int n);
    void backtrack(int);
    bool is_place(int,int);
    void place(int,int);
    void displace(int,int);
    void addanswer();
};

void Solution::addanswer(){//将当前set集合中的点转化为
    vector<string> possible_answer(N);
    set<pair<int,int>>:: iterator iter=qipan.begin();
    while(iter!=qipan.end()){
        string s(N,'.');
        int rows=(*iter).first;
        int cols=(*iter).second;
        s[cols]='Q';
        possible_answer[rows]=s;
        iter++;
    }
    answers.push_back(possible_answer);
}

bool Solution::is_place(int row,int col){
    return columns[col]&&left_diagonals[row+col]&&right_diagonals[N+row-col-1];//必须都是true
}

void Solution::displace(int row,int col){
    pair<int,int> queen(row,col);
    qipan.erase(queen);
    columns[col]=true;//标记不可放置区域
    left_diagonals[row+col]=true;
    right_diagonals[N+row-col-1]=true;    
}

void Solution::place(int row,int col){
    pair<int,int> queen(row,col);
    qipan.insert(queen);//放置在棋盘上
    columns[col]=false;//标记不可放置区域
    left_diagonals[row+col]=false;
    right_diagonals[N+row-col-1]=false;

}

vector<vector<string>> Solution:: solveNQueens(int n){
    columns.resize(n);
    left_diagonals.resize(2*n-1);
    right_diagonals.resize(2*n-1);
    N=n;
    for(int i=0;i<columns.size();i++) columns[i]=true;//初始化为可放置
    for(int i=0;i<left_diagonals.size();i++) left_diagonals[i]=right_diagonals[i]=true;//初始化为可放置
    backtrack(0);
    return answers;
}

void Solution::backtrack(int row){//回溯法，从第n行开始
    for(int col=0;col<N;col++){//判断第row行，第col列是否可以放置棋子
        if(is_place(row,col)){//可以放置
            place(row,col);
            if(row==N-1){//向结果集合中加入本结果【同时也是递归的退出条件】
                addanswer();
            }else{//递归调用回溯法
                backtrack(row+1);
            }
            displace(row,col);
        }//不可以放置直接探索下一个位置
    }
}


int main(){
    int n=5;
    Solution so;
    vector<vector<string>> ans=so.solveNQueens(n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}