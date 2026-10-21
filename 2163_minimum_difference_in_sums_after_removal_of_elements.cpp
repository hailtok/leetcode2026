// Problem 2163: Minimum Difference in Sums After Removal of Elements
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        vector<long long>min_left(nums.size(),0);
        vector<long long>max_right(nums.size(),0);
        priority_queue<int>pq_l;
        long long current_left_sum=0;
        for (int i=0;i<n;++i) {
            current_left_sum+=nums[i];
            pq_l.push(nums[i]);
        }
        min_left[n-1]=current_left_sum;
        for (int i=n;i<2*n;++i) {
            current_left_sum+=nums[i];
            pq_l.push(nums[i]);
            current_left_sum-=pq_l.top();
            pq_l.pop();
            min_left[i] = current_left_sum;
        }
        priority_queue<int,vector<int>,greater<int>>pq_r;
        long long current_right_sum=0;
        for (int i=nums.size()-1;i>=2*n;--i) {
            current_right_sum +=nums[i];
            pq_r.push(nums[i]);
        }
        max_right[2*n]=current_right_sum;
        for (int i=2*n-1;i>= n;--i) {
            current_right_sum+=nums[i];
            pq_r.push(nums[i]);
            current_right_sum-=pq_r.top();
            pq_r.pop();
            max_right[i]=current_right_sum;
        }
        long long ans =LLONG_MAX;
        for (int i=n-1;i<2*n;++i) {
            ans=min(ans,min_left[i]-max_right[i+1]);
        }
        return ans;
    }
};