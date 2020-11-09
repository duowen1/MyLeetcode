#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{
private:
    //行、列、9宫格的不可选集
    vector<set<int>> rows;
    vector<set<int>> cols;
    vector<set<int>> tabs;
    vector<vector<char>> boards;
    bool flag;
public:
    void solveSudoku(vector<vector<char>>& board);
    int tabnum(int,int);
    void backtrack(int,int);
    void place(int,int,int);
    void displace(int,int,int);
};

void Solution::displace(int i,int j,int m){
    rows[i].erase(m);
    cols[j].erase(m);
    tabs[tabnum(i,j)].erase(m);
    boards[i][j]='.';
}

void Solution::place(int i,int j,int m){
    rows[i].insert(m);
    cols[j].insert(m);
    tabs[tabnum(i,j)].insert(m);
    boards[i][j]=m+'0';
}

int Solution::tabnum(int i,int j){
    return 3*(i/3)+j/3;
}

void Solution::backtrack(int i,int j){
    if(boards[i][j]!='.'){//如果已经预置，开启下一次回溯
        if(i==8&&j==8){
            flag=true;
            return;
        }
        if(j!=8) backtrack(i,j+1);
        else backtrack(i+1,0);
    }else{
        for(int m=1;m<=9;m++){//试探可以为几
            if(rows[i].count(m)+cols[j].count(m)+tabs[tabnum(i,j)].count(m)) continue;//是否冲突，冲突直接测试下一个
            place(i,j,m);//放置
            if((i==8&&j==8)||flag){//终止回溯
                flag=true;
                return;
            }
            else{
                if(j!=8) backtrack(i,j+1);
                else backtrack(i+1,0);
                if(flag) return;
                displace(i,j,m);
            }
        }
    }
}

void Solution :: solveSudoku(vector<vector<char>> & board){
    boards=board;
    flag=false;
    //初始化各个可选集
    rows.resize(9);
    cols.resize(9);
    tabs.resize(9);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.') continue;
            rows[i].insert(board[i][j]-'0');
            cols[j].insert(board[i][j]-'0');
            tabs[tabnum(i,j)].insert(board[i][j]-'0');
        }
    }
    backtrack(0,0);
    board=boards;
}

int main(){
    Solution s;
    vector<vector<char>> board={
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};
    s.solveSudoku(board);
}

