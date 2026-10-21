// Problem 11: Container With Most Water
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int begin=0,end=height.size()-1,max_area=0;
        while(begin!=end){
            if(max_area<min(height[begin],height[end])*(end-begin)){
                max_area=min(height[begin],height[end])*(end-begin);
            }
            if(height[begin]>height[end]){
                end--;
            }
            else{
                begin++;
            }
        }
        return max_area;
    }
};