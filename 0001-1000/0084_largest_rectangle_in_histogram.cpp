// Problem 84: Largest Rectangle in Histogram
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        stack<int>stack;
        stack.push(-1);
        for(int i=0;i<heights.size();++i){
            while(stack.top()!=-1&&heights[i]<=heights[stack.top()]){
                int height=heights[stack.top()];
                stack.pop();
                int width=i-stack.top()-1;
                ans=std::max(ans,height*width);     
            }
            stack.push(i);
        }
        while(stack.top()!=-1){
            int height=heights[stack.top()];
            stack.pop();
            int width=heights.size()-stack.top()-1;
            ans=std::max(ans,height*width);
        }
        return ans;
    }
};