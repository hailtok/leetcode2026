// Problem 3785: Minimum Swaps to Avoid Forbidden Values
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/minimum-swaps-to-avoid-forbidden-values/

class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n=static_cast<int>(nums.size());
        unordered_map<int,int>total_cnt;
        unordered_map<int,int>bad_cnt;
        int bad_total=0;
        int max_bad=0;
        for(int i=0;i<n;++i) {
            total_cnt[nums[i]]++;
            total_cnt[forbidden[i]]++;
            if (nums[i]==forbidden[i]) {
                bad_total++;
                bad_cnt[nums[i]]++;
                max_bad=max(max_bad,bad_cnt[nums[i]]);
            }
        }
        for(auto it=total_cnt.begin();it!=total_cnt.end();++it){
            if(it->second>n){
                return -1;
            }
        }
        if(bad_total==0) {
            return 0;
        }
        return max(max_bad,(bad_total+1)/2);
    }
};