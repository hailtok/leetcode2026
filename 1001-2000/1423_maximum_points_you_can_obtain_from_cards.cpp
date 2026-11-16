// Problem 1423: Maximum Points You Can Obtain from Cards
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int>prefix(k,0),suffix(k,0);
        prefix[0]=cardPoints[0];
        suffix[0]=cardPoints.back();
        for(int i=1;i<k;++i){
            prefix[i]=prefix[i-1]+cardPoints[i];
            suffix[i]=suffix[i-1]+cardPoints[cardPoints.size()-i-1];
        }
        int ans=std::max(prefix.back(),suffix.back());
        for(int i=0;i<k-1;++i){
            ans=std::max(ans,prefix[i]+suffix[k-i-2]);
        }
        return ans;
    }
};