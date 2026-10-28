// Problem 275: H-Index II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/h-index-ii/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left=0,right=citations.size()-1,mid=0;
        while(left<=right){
            mid=left+(right-left)/2;
            if(citations[mid]>citations.size()-mid){
                right=mid-1;
            }
            else if(citations[mid]<citations.size()-mid){
                left=mid+1;
            }
            else{
                return citations.size()-mid;
            }
        }
        return citations.size()-left;
    }
};