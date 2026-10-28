// Problem 3206: Alternating Groups I
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/alternating-groups-i/

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int pre=colors[0],last=colors[1],answer=0;
        for(int i=0;i<colors.size();++i){
            if(pre!=last&&last!=colors[(i+2)%colors.size()]){
                answer++;
            }
            pre=last;
            last=colors[(i+2)%colors.size()];
        }
        return answer;
    }
};