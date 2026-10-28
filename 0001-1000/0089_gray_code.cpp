// Problem 89: Gray Code
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/gray-code/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>output{0};
        int size=int(pow(2,n)),total=0,zero_index=1;;
        vector<bool>gray_code(n);
        for(int i=0;i<size-1;i++){
            if(i%2==0){
                if(gray_code[0]){
                    gray_code[0]=false;
                    total--;
                }
                else{
                    gray_code[0]=true;
                    zero_index=1;
                    total++;
                }
            }
            else{
                if(gray_code[zero_index]){
                    gray_code[zero_index]=false;
                    total-=int(pow(2,zero_index));
                }
                else{
                    gray_code[zero_index]=true;
                    total+=int(pow(2,zero_index));
                }
                while(!gray_code[zero_index]){
                    zero_index=(zero_index+1)%n;
                }
                zero_index++;
            }
            output.push_back(total);
        }
        return output;
    }
};