// Problem 2657: Find the Prefix Common Array of Two Arrays
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>count_arr(A.size(),1);
        vector<int>ans(A.size(),0);
        int count=0;
        for(int i=0;i<A.size();++i){
            if(count_arr[A[i]-1]==0){
                ++count;
            }
            --count_arr[A[i]-1];
            if(count_arr[B[i]-1]==0){
                ++count;
            }
            --count_arr[B[i]-1];
            ans[i]=count;
        }
        return ans;
    }
};