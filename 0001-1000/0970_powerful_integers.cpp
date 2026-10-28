// Problem 970: Powerful Integers
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/powerful-integers/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int>uset;
        for(int i=1;i<bound;i*=x){
            for(int j=1;i+j<=bound;j*=y){
                uset.insert(i+j);
                if(y==1){
                    break;
                }
            }
            if(x==1){
                break;
            }
        }
        return vector<int>(uset.begin(),uset.end());
    }
};