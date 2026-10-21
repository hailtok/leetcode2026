// Problem 350: Intersection of Two Arrays II
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>answer;
        for(int i=0,j=0;i<nums1.size()&&j<nums2.size();){
            if(nums1[i]==nums2[j]){
                answer.push_back(nums1[i]);
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