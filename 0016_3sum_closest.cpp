// Problem 16: 3Sum Closest
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int output,gap=INT_MAX;;
        for(int i=0;i<nums.size()-2;i++){
            int right=nums.size()-1,left=i+1;
            while(right!=left){
                int sum=nums[right]+nums[left],current_sum=sum+nums[i];
                if(gap>abs(target-current_sum)){
                    gap=abs(target-current_sum);
                    output=current_sum;
                }
                if(target-current_sum>0){
                    left++;                    
                }
                else{
                    right--;
                }
                if(gap==0){
                    return target;
                }   
            }
        }
        return output;
    }
};