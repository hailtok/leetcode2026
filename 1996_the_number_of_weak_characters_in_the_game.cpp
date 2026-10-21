// Problem 1996: The Number of Weak Characters in the Game
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end());
        int attack1=properties[properties.size()-1][0],defense1=properties[properties.size()-1][1],output=0,last_max=defense1;
        for(int i=properties.size()-2;i>=0;i--){
            if(properties[i][0]<properties[i+1][0]){
                defense1=max(defense1,last_max);
                last_max=max(defense1,properties[i][1]);
            }
            if(attack1>properties[i][0]&&defense1>properties[i][1]){
                output++;
            }
        }
        return output;
    }
};