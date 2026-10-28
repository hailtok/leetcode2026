// Problem 332: Reconstruct Itinerary
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/reconstruct-itinerary/

class Solution {
public:
    vector<string> answer;
    void dfs(string airport,unordered_map<string,vector<string>>&graph){
        vector<string> &destinations = graph[airport];
        while (!destinations.empty()) {
            string nextDestination = destinations.back();
            destinations.pop_back();
            dfs(nextDestination,graph);
        }
        answer.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>graph;
        for(int i=0;i<tickets.size();++i){
            graph[tickets[i][0]].push_back(tickets[i][1]);
        }
        for(auto begin=graph.begin();begin!=graph.end();++begin){
            sort(begin->second.rbegin(),begin->second.rend());
        }
        dfs("JFK",graph);
        reverse(answer.begin(), answer.end());
        return answer;
    }
};