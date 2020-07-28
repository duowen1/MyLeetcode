#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums);
    int print(vector<int> & nums);
};

vector<vector<int>> Solution :: threeSum(vector<int> & nums){
    vector<vector<int>> answer;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int first=0;first<n;first++){
        if(first>0&&nums[first]==nums[first-1]) continue;//如果和上一个重复
        for(int second=first+1;second<n;second++){
            if(second>0&&nums[second]==nums[second-1]) continue;
            int third=n-1;//此时第三个指针指向末尾
            while(third>second&&(nums[first]+nums[second]+nums[third])>0){
                third--;
            }
            if(second==third) break;
            if((nums[first]+nums[second]+nums[third])==0){//满足条件
                vector<int> element={nums[first],nums[second],nums[third]};
                answer.push_back(element);
            }
        }
    }
    return answer;
}


int Solution :: print(vector<int> &nums){
    vector<vector<int>> answers=this->threeSum(nums);
    int n=answers.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++) cout<<answers[i][j]<<',';
        cout<<endl;
    }
    return n;
}


int main(){
    Solution so;
    vector<int> nums={-1,0,1,2,-1,-4};
    return so.print(nums);
}