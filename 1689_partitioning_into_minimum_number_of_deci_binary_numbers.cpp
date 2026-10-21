// Problem 1689: Partitioning Into Minimum Number Of Deci-Binary Numbers
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

class Solution {
public:
    int minPartitions(string n) {
        int output=0;
        for(int i=0;i<n.size();i++){
            if(n[i]-'0'>output){
                output=n[i]-'0';
            }
        }
        return output;
    }
};