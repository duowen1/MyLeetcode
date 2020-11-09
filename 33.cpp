#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target);
};

int Solution::search(vector<int> &nums,int target){
    if(!nums.size()) return -1;
    int left=0;
    int right=nums.size()-1;
    int mid;
    while(left<=right){
        mid=(left+right)/2;
        if((mid>0&&nums[mid]<nums[mid-1])) break;
        if(nums[mid]<*(--nums.end())) right=mid-1;
        else left=mid+1;;
    }
    cout<<mid<<endl;
    if(target>*(--nums.end())){//在左半区里找
        left=0;
        right=mid-1;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
    }else{
        left=mid;
        right=nums.size()-1;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) left=mid+1;
            else right=mid-1;
        }        
    }
    return -1;

}

int main(){
    vector<int> nums={0,1,2};
    int target=1;
    Solution so;
    cout<<so.search(nums,target)<<endl;
    return 0;
}