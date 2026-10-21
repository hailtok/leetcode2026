// Problem 2033: Minimum Operations to Make a Uni-Value Grid
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>numbers(grid.size()*grid[0].size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                numbers[i*grid[0].size()+j]=grid[i][j];
            }
        }
        sort(numbers.begin(),numbers.end());
        int middle=numbers[numbers.size()/2],output=0;
        for(int i=0;i<numbers.size();i++){
            if(abs(numbers[i]-middle)%x!=0){
                return -1;
            }
            else{
                output+=abs(numbers[i]-middle)/x;
            }
        }
        return output;
    }
};