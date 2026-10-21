// Problem 3100: Water Bottles II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/water-bottles-ii/

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty=numBottles,answer=numBottles;
        while(empty>=numExchange){
            empty-=numExchange;
            empty++;
            answer++;
            numExchange++;
        }
        return answer;
    }
};