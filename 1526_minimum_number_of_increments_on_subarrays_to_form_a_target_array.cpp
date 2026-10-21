// Problem 1526: Minimum Number of Increments on Subarrays to Form a Target Array
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        stack<int>s;
        int ans=target[0];
        s.push(target[0]);
        for(int i=1;i<target.size();++i){
            if(target[i]>s.top()){
                ans+=target[i]-s.top();
                s.push(target[i]);
            }
            else{
                while(!s.empty()&&target[i]<s.top()){
                    s.pop();
                }
                s.push(target[i]);
            }
        }
        return ans;
    }
};