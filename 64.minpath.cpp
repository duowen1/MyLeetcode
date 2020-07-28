#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int minPathSum(vector<vector<int>>& grid);
};

int Solution::minPathSum(vector<vector<int>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    int i,j;
    for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            grid[i][j]+=(grid[i-1][j]<grid[i][j-1])?grid[i-1][j]:grid[j-1][i];
        }
    }
    return grid[i-1][j-1];
}

int main(){
    Solution mySo;

    return 0;
}