// Problem 1385: Find the Distance Value Between Two Arrays
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=arr1.size();
        for(int i=0;i<arr1.size();++i){
            for(int j=0;j<arr2.size();++j){
                if(std::abs(arr1[i]-arr2[j])<=d){
                    --ans;
                    break;
                }
            }
        }
        return ans;
    }
};