// Problem 1818: Minimum Absolute Sum Difference
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-absolute-sum-difference/

class Solution {
public:
    int binary_search(vector<int>&array,int left,int right,int& target){
        if(left==right){
            return left;
        }
        int mid=left+(right-left)/2;
        if(array[mid]==target){
            return mid;
        }
        if(array[mid]>=target){
            return binary_search(array,left,mid,target);
        }
        return binary_search(array,mid+1,right,target);
    }
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long diff=0,ans=LLONG_MAX;
        int base=1e9+7;
        for(int i=0;i<nums1.size();++i){
            diff+=std::abs(nums1[i]-nums2[i]);
        }
        vector<int>temp_array=nums1;
        std::sort(nums1.begin(),nums1.end());
        long long temp=diff;
        for(int i=0;i<nums1.size();++i){
            temp=diff;
            temp-=std::abs(temp_array[i]-nums2[i]);
            int index=binary_search(nums1,0,nums1.size()-1,nums2[i]);
            if(index!=0){
                temp+=std::min(std::abs(nums1[index]-nums2[i]),std::abs(nums1[index-1]-nums2[i]));
            }
            else{
                temp+=std::abs(nums1[index]-nums2[i]);
            }
            ans=std::min(ans,temp);
        }
        return ans%base;
    }
};