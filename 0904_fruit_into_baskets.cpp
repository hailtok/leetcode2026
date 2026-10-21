// Problem 904: Fruit Into Baskets
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int type1=fruits[0],type2=-1,ans=1,index1=0,index2=-1,cur=1;
        for(int i=1;i<fruits.size();++i){
            if(fruits[i]==type1){
                ++cur;
                index1=i;
            }
            else if(fruits[i]==type2){
                ++cur;
                index2=i;
            }
            else if(type2==-1){
                type2=fruits[i];
                index2=i;
                ++cur;
            }
            else{
                ans=std::max(ans,cur);
                if(index2>index1){
                    cur=i-index1;
                    index1=index2;
                    type1=type2;
                }
                else{
                    cur=i-index2;
                }
                index2=i;
                type2=fruits[i];
                cout<<cur<<endl;
            }
        }
        ans=std::max(ans,cur);
        return ans;
    }
};