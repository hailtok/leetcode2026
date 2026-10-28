// Problem 1104: Path In Zigzag Labelled Binary Tree
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int>ans;
        int temp=label,base=1;
        while(label>=base){
            ans.push_back(base);
            base<<=1;
        }
        if(ans.size()%2){
            label=base-label+(base>>1)-1;
            cout<<label<<endl;
        }
        for(int i=ans.size()-1;i>=0;--i){
            ans[i]=label;
            label>>=1;
        }
        base=8;
        for(int i=2;i<ans.size();i+=2){
            ans[i]=base-ans[i]+base/2-1;
            base<<=2;
        }
        ans.back()=temp;
        return ans;
    }
};