#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution{
private:
    int N;
    int answers;
    vector<bool> columns;//当前列是否可以放置
    vector<bool> left_diagonals;//左向对角线是否可以放置
    vector<bool> right_diagonals;//右向对角线是否可以放置
    set<pair<int,int>> qipan;//保存皇后的位置

public:
    int totalNQueens(int n);
    void backtrack(int);
    bool is_place(int,int);
    void place(int,int);
    void displace(int,int);
};

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

int Solution:: totalNQueens(int n){
    columns.resize(n);
    left_diagonals.resize(2*n-1);
    right_diagonals.resize(2*n-1);
    N=n;
    answers=0;
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
                answers++;
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
    cout<<so.totalNQueens(n);
    return 0;
}