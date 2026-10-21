// Problem 1860: Incremental Memory Leak
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/incremental-memory-leak/

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        vector<int>output(3);
        int program=1;
        while(memory1>=program||memory2>=program){
            if(memory1>=memory2){
                memory1-=program;
            }
            else{
                memory2-=program;
            }
            program++;
        }
        output[0]=program;
        output[1]=memory1;
        output[2]=memory2;
        return output;
    }
};