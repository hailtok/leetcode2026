// Problem 349: Intersection of Two Arrays
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>answer;
        for(int i=0,j=0;i<nums1.size()&&j<nums2.size();){
            if(nums1[i]==nums2[j]){
                if(answer.empty()||answer.back()!=nums1[i]){
                    answer.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return answer;
    }
};