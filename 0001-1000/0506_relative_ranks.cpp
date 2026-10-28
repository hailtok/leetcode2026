// Problem 506: Relative Ranks
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/relative-ranks/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> heap;
        for(int i=0;i<score.size();i++){
            heap.push({score[i],i});
        }
        vector<string> answer(score.size());
        int place=1;
        while(!heap.empty()){
            if(place==1){
                answer[heap.top().second]="Gold Medal";
            }
            else if(place==2){
                answer[heap.top().second]="Silver Medal";
            }
            else if(place==3){
                answer[heap.top().second]="Bronze Medal";
            }
            else{
                answer[heap.top().second]=to_string(place);
            }
            heap.pop();
            place++;
        }
        return answer;
    }
};