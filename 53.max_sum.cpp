#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    int maxSubArray(vector<int>& nums);
};

int main(){
    Solution so;
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<so.maxSubArray(nums)<<endl;
    return 0;
}

int Solution::maxSubArray(vector<int> & nums){
    vector<int> max_until(nums.size());
    for(int i=0;i<nums.size();i++){
        if(i==0){
            max_until[0]=nums[0];
            continue;
        }
        max_until[i]=max(max_until[i-1]+nums[i],nums[i]);
    }
    return *max_element(max_until.begin(),max_until.end());
}