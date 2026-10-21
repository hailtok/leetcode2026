// Problem 135: Candy
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int candy=ratings.size(),base=0,index=1;
        while(index<ratings.size()){
            int max=0;
            if(ratings[index]==ratings[index-1]){
                ++index;
                continue;
            }
            while(index<ratings.size()&&ratings[index]>ratings[index-1]){
                ++max;
                candy+=max;
                ++index;
            }
            int min=0;
            while(index<ratings.size()&&ratings[index]<ratings[index-1]){
                ++min;
                candy+=min;
                ++index;
            }
            candy-=std::min(max,min);
        }
        return candy;
    }
};