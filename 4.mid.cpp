#include <iostream>
#include <vector>
using namespace std;

/*
实际上遍历的是空格
*/

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1,vector <int>& nums2);
};

double Solution :: findMedianSortedArrays(vector<int>& nums1, vector <int>& nums2){
    /*
    如果合并两个数组，再求中位数，复杂度为O(m+n)
    要求复杂度为O(log(m+n))，又是有序数组，故想到二分查找
    假设两个数组已经被合并成一个大数组，可以得知，中位数前面的共有(m+n)/2个元素
    这些元素都来自于两个数组，不妨设nums1贡献了l1个，nums2贡献了l2个，显然l1+l2=(m+n)/2
    根据中位数的特点可以得知，nums1[l1]<=mid<=nums2[l2+1]，且nums2[l2]<=mid<=nums1[l1+1]
    故可以通过二分查找l1或者l2获得中位数
    */
    int nums1_n=nums1.size();
    int nums2_n=nums2.size();
    int length=nums1_n+nums2_n;//总数
    if(nums1_n>nums2_n) return findMedianSortedArrays(nums2,nums1);//保证了第一个数组的长度较小
    if(nums1_n==0){//返回nums2的中位数
        if(length%2) return nums2[length/2];
        else return (nums2[length/2]+nums2[length/2-1])/2.0;
    }
    int left=0;
    int right=nums1_n-1;
    int mid,mid_2;
    while(left<=right){
        /*
        L1=nums1[0:mid],R1=nums1[mid+1:nums1_n-1]
        L2=nums1[0:mid_2],R2=nums2[mid_2+1,nums2_n-1]
        */
        mid=(left+right)/2;//有mid+1个
        mid_2=(length+1)/2-(mid+1)-1;
        /*
        总数是偶数时，L1、L2数量和为总数的一半
        总数时奇数时，L1、L2数量和为总数+1的一半
        */
        int L1max=(mid==0?INT_MIN:nums1[mid]);
        int R1min=(mid==nums1_n-1?INT_MAX:nums1[mid+1]);
        int L2max=(mid_2==0?INT_MIN:nums2[mid_2]);
        int R2min=(mid_2==nums2_n-1?INT_MAX:nums2[mid_2+1]);
        if(L1max<=R2min){
            /*
            此时满足条件1，满足条件2时，退出
            */
            if(R1min>=L2max) break;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    //奇数返回中值，偶数返回平均数
    if(length%2){//old
        return max(nums1[mid],nums2[mid_2]);
    }else{
        return (max(nums1[mid],nums2[mid_2])+min(nums1[mid+1],nums2[mid_2+1]))/2.0;
    }
}

int main(){
    vector<int> nums1={1,3};
    vector<int> nums2={2};
    Solution so;
    cout<<so.findMedianSortedArrays(nums1,nums2)<<endl;
}