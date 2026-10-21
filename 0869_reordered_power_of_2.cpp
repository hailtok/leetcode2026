// Problem 869: Reordered Power of 2
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/reordered-power-of-2/

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string target=to_string(n);
        std::sort(target.begin(),target.end());
        for(int i=0;i<31;++i){
            string temp=to_string(1<<i);
            std::sort(temp.begin(),temp.end());
            if(target==temp){
                return true;
            }
        }
        return false;
    }
};