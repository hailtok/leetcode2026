// Problem 912: Sort an Array
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/sort-an-array/

class Solution {
public:
    void sort(vector<int>&arr,int left,int right){
        if(right-left<=1){
            return;
        }
        if(right-left==2){
            if(arr[left]>arr[left+1]){
                std::swap(arr[left],arr[left+1]);
            }
            return;
        }
        int pivot=left+(right-left)/2;
        vector<int>l_arr,r_arr;
        for(int i=left;i<right;++i){
            if(arr[i]<arr[pivot]){
                l_arr.push_back(arr[i]);
            }
            else{
                r_arr.push_back(arr[i]);
            }
        }
        for(int i=0;i<r_arr.size();++i){
            l_arr.push_back(r_arr[i]);
        }
        for(int i=left,j=0;i<right;++i,++j){
            arr[i]=l_arr[j];
        }
        sort(arr,left,pivot);
        sort(arr,pivot,right);
        vector<int>temp;
        int l=left,r=pivot;
        for(int i=left,l=left,r=pivot;i<right;++i){
            if(l<pivot){
                if(r==right||arr[l]<arr[r]){
                    temp.push_back(arr[l]);
                    ++l;
                }
                else{
                    temp.push_back(arr[r]);
                    ++r;
                }
            }
            else{
                temp.push_back(arr[r]);
                ++r;
            }
        }
        for(int i=left,j=0;i<right;++i,++j){
            arr[i]=temp[j];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        sort(nums,0,nums.size());
        return nums;
    }
};