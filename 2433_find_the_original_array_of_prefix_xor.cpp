// Problem 2433: Find The Original Array of Prefix Xor
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>answer(pref.size());
        answer[0]=pref[0];
        for(int i=1;i<pref.size();i++){
            answer[i]=pref[i-1]^pref[i];
        }
        return answer;
    }
};