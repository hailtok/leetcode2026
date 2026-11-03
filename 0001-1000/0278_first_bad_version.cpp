// Problem 278: First Bad Version
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1){
            return 1;
        }
        int l=0,r=n,ans=-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(isBadVersion(mid)){
                if(isBadVersion(mid+1)){
                    r=mid;
                }
                else{
                    ans=mid+1;
                    break;
                }
            }
            else{
                if(isBadVersion(mid+1)){
                    ans=mid+1;
                    break;
                }
                else{
                    l=mid;
                }
            }
        }
        return ans;
    }
};