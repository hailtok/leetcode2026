// Problem 2937: Make Three Strings Equal
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/make-three-strings-equal/

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int index=0,size=std::min({s1.size(),s2.size(),s3.size()});
        for(int i=0;i<size;++i){
            if(s1[i]!=s2[i]||s2[i]!=s3[i]){
                break;
            }
            ++index;
        }
        if(index==0){
            return -1;
        }
        return s1.size()+s2.size()+s3.size()-3*index;
    }
};