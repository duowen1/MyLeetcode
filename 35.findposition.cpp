#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int searchInsert(vector<int>& nums,int target);
};

int main(){
    Solution so;
    vector<int> nums={1,3,5,6};
    int answer=so.searchInsert(nums,2);
    cout<<answer<<endl;
}

int Solution::searchInsert(vector<int>& nums,int target){
    if(nums.empty()) return 0;
    int left=0;
    int right=nums.size()-1;
    int mid;
    while(left<=right){
        if(target<=nums[left]) return left;
        if(target>nums[right]) return right+1;
        mid=(left+right)/2;
        if(target==nums[mid]) return mid;
        if(target>nums[mid]) left=mid+1;
        else right=mid-1;
    }
    return 0;
}