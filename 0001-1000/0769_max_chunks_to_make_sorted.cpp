// Problem 769: Max Chunks To Make Sorted
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/max-chunks-to-make-sorted/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int answer=0,total=0;
        for(int left=0,right=0;right<arr.size();++right){
            total+=arr[right];
            if(total==(right-left)*(right+left+1)/2){
                answer++;
                left=right;
                total=0;
            }
        }
        return answer;
    }
};