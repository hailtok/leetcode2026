// Problem 765: Couples Holding Hands
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/couples-holding-hands/

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans=row.size()/2;
        for(int i=0;i<row.size();i+=2){
            int couple=(row[i]&1)==0?row[i]+1:row[i]-1;
            cout<<couple<<endl;
            if(row[i+1]==couple){
                --ans;
            }
            else{
                for(int j=i+1;j<row.size();++j){
                    if(row[j]==couple){
                        swap(row[i+1],row[j]);
                    }
                }
            }
        }
        return ans;
    }
};