// Problem 62: Unique Paths
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/unique-paths/

class Solution {
public:
    int uniquePaths(int m, int n) {
        unsigned long long output=1,big,small;
        if(m>n){
            big=m-1;
            small=n-1;
        }
        else{
            big=n-1;
            small=m-1;
        }
        if(small==0){
            return small+1;
        }
        for(int i=big+small,temp=1;i>big;i--){
            output*=i;
            if(output%temp==0){
                output/=temp;
                temp++;
            }
        }
        return output;
    }
};