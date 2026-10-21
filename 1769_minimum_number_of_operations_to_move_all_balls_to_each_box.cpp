// Problem 1769: Minimum Number of Operations to Move All Balls to Each Box
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>output(boxes.size());
        int sum=0,cur_sum=0,count=0,cur_count=0;
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1'){
                sum+=i;
                count++;
            }
        }
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1'){
                cur_count++;
                cur_sum+=i;
            }
            output[i]=cur_count*i+(sum-cur_sum)-i*(count-cur_count)-cur_sum;
        }
        return output;
    }
};