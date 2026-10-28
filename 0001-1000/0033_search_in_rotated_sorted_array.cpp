// Problem 33: Search in Rotated Sorted Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int ans=-1,pivot=0;
    void find_pivot(vector<int>&array,int left,int right){
        if(left==right){
            return;
        }
        int mid=left+(right-left)/2;
        if(array[mid]>array[(mid+1)%array.size()]){
            pivot=mid;
            return;
        }
        if(array[left]<array[mid]){
            find_pivot(array,mid+1,right);
        }
        else{
            find_pivot(array,left,mid);
        }
    }
    void binary_search(vector<int>&array,int left,int right,int& target){
        int mid=left+(right-left)/2;
        if(array[mid]==target){
            ans=mid;
            return;
        }
        if(left==right){
            return;
        }
        if(array[mid]>target){
            binary_search(array,left,mid,target);
        }
        else{
            binary_search(array,mid+1,right,target);
        }
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target){
                return 0;
            }
            return -1;
        }
        pivot=nums.size()-1;
        find_pivot(nums,0,nums.size()-1);
        cout<<pivot<<endl;
        binary_search(nums,0,pivot,target);
        if(pivot+1<=nums.size()-1){
            binary_search(nums,pivot+1,nums.size()-1,target);
        }
        return ans;
    }
};