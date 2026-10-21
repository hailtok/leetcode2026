// Problem 374: Guess Number Higher or Lower
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/guess-number-higher-or-lower/

class Solution {
public:
    int guessNumber(int n) {
        int left=0;
        while(left!=n){
            int mid=left+(n-left)/2;
            if(guess(mid)==0){
                return mid;
            }
            else if(guess(mid)>0){
                left=mid+1;
            }
            else{
                n=mid-1;
            }
        }
        if(guess(left)==0){
            return left;
        }
        return -1;
    }
};