#include <iostream>
#include <vector>
using namespace std;

class Solution{
    vector<vector<int>> answer;
    vector<int> solutions;
    vector<int> global;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    void turtle(int,int);
};

void Solution::turtle(int start,int target){
    if(target==0){
        answer.push_back(solutions);
    }

    for(int i=start;i<global.size();i++){
        if(global[i]>target) break;
        solutions.push_back(global[i]);
        turtle(i,target-global[i]);
        solutions.pop_back();
    }

}

vector<vector<int>> Solution::combinationSum(vector<int>& candidates,int target){
    sort(candidates.begin(),candidates.end());
    global=candidates;
    turtle(0,target);
    return answer;
}

int main(){
    Solution so;
    vector<int> candidates={2,3,6,7};
    int target=7;
    auto solution=so.combinationSum(candidates,target);
    for(int i=0;i<solution.size();i++){
        for(int j=0;j<solution[i].size();j++){
            cout<<solution[i][j];
        }
        cout<<endl;
    }
    return 0;
}