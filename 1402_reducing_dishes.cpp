// Problem 1402: Reducing Dishes
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/reducing-dishes/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        std::sort(satisfaction.begin(),satisfaction.end());
        int sum=0,ans=0,temp=0;
        for(int i=0;i<satisfaction.size();++i){
            temp+=satisfaction[i]*(i+1);
            sum+=satisfaction[i];
        }
        ans=std::max(ans,temp);
        for(int i=0;i<satisfaction.size();++i){
            temp-=sum;
            sum-=satisfaction[i];
            ans=std::max(ans,temp);
        }
        return ans;
    }
};