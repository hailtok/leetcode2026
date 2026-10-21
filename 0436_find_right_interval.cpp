// Problem 436: Find Right Interval
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-right-interval/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int>ans(intervals.size());
        vector<int>start(intervals.size());
        unordered_map<int,int>umap;
        for(int i=0;i<intervals.size();++i){
            start[i]=intervals[i][0];
            umap[intervals[i][0]]=i;
        }
        sort(start.begin(),start.end());
        for(int i=0;i<ans.size();++i){
            int index=minimum_larger(start,0,ans.size(),intervals[i][1]);
            cout<<index<<endl;
            if(index==ans.size()){
                ans[i]=-1;
            }
            else if(umap.count(start[index])>0){
                ans[i]=umap[start[index]];
            }
        }
        return ans;
    }
    int minimum_larger(vector<int>&array,int left,int right,int &val){
        if(left>=right){
            return left;
        }
        int mid=left+(right-left)/2;
        if(array[mid]>=val){
            return minimum_larger(array,left,mid,val);
        }
        return minimum_larger(array,mid+1,right,val);
    }
};