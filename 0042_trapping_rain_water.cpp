// Problem 42: Trapping Rain Water
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int output=0,max_index=0;
        for(int i=1;i<height.size();i++){
            if(height[max_index]<height[i]){
                max_index=i;
            }
        }
        for(int i=1,cur_max=height[0];i<max_index;i++){
            if(cur_max>height[i]){
                output+=cur_max-height[i];
            }
            else{
                cur_max=height[i];
            }
        }
        for(int i=height.size()-2,cur_max=height[height.size()-1];i>max_index;i--){
            if(cur_max>height[i]){
                output+=cur_max-height[i];
            }
            else{
                cur_max=height[i];
            }
        }
        return output;
    }
};