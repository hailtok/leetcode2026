// Problem 735: Asteroid Collision
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int position=1;
        while(position<asteroids.size()){
            if(asteroids[position]>0||asteroids[position]*asteroids[position-1]>0){
                position++;
            }
            else if(abs(asteroids[position])<asteroids[position-1]){
                asteroids.erase(asteroids.begin()+position);
            }
            else if(abs(asteroids[position])>asteroids[position-1]){
                asteroids.erase(asteroids.begin()+position-1);
                if(position!=1)
                position--;
            }
            else{
                asteroids.erase(asteroids.begin()+position-1,asteroids.begin()+position+1);
                if(position!=1)
                position--;
            }
        }
        return asteroids;
    }
};