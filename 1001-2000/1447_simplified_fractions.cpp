// Problem 1447: Simplified Fractions
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/simplified-fractions/

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>output;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(__gcd(i,j)==1){
                    output.push_back(to_string(i)+'/'+to_string(j));
                }
            }
        }
        return output;
    }
};