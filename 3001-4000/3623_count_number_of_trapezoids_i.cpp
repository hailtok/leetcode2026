// Problem 3623: Count Number of Trapezoids I
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-number-of-trapezoids-i/

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long mod=1e9+7,sum=0,ans=0;
        unordered_map<int,long long>umap;
        for(int i=0;i<points.size();++i){
            ++umap[points[i][1]];
        }
        for(auto it=umap.begin();it!=umap.end();++it){
            sum+=(it->second*(it->second-1))/2;
        }
        for(auto it=umap.begin();it!=umap.end();++it){
            sum-=(it->second*(it->second-1))/2;
            ans+=(it->second*(it->second-1))/2*sum;
        }
        return ans%mod;
    }
};