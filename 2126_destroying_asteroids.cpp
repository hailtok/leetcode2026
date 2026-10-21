// Problem 2126: Destroying Asteroids
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/destroying-asteroids/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long mass_l=mass;
        std::sort(asteroids.begin(),asteroids.end());
        for(auto& asteroid:asteroids){
            if(mass_l<asteroid){
                return false;
            }
            else{
                mass_l+=asteroid;
            }
        }
        return true;
    }
};