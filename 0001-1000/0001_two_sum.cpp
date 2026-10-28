// Problem 1: Two Sum
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>temp=nums;
        sort(nums.begin(),nums.end());
        int begin=0,end=nums.size()-1;
        while(begin!=end){
            if(nums[begin]+nums[end]>target){
                end--;
            }
            else if(nums[begin]+nums[end]<target){
                begin++;
            }
            else{
                int first=std::find(temp.begin(),temp.end(),nums[begin])-temp.begin();
                int second=0;
                if(nums[begin]*2==target){
                    auto first_index=std::find(temp.begin(),temp.end(),nums[begin]);
                    second=std::find(first_index+1,temp.end(),nums[end])-temp.begin();
                }
                else{
                    second=std::find(temp.begin(),temp.end(),nums[end])-temp.begin(); 
                }
                return vector<int>{first,second};
            }
        }
        int first=std::find(temp.begin(),temp.end(),nums[begin])-temp.begin();
        int second=0;
        if(nums[begin]*2==target){
            auto first_index=std::find(temp.begin(),temp.end(),nums[begin]);
            second=std::find(first_index+1,temp.end(),nums[end])-temp.begin();
        }
        else{
            second=std::find(temp.begin(),temp.end(),nums[end])-temp.begin(); 
            }
        return vector<int>{first,second};        
    }
};