// Problem 768: Max Chunks To Make Sorted II
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        int answer=0;
        long long total1=0,total2=0;
        for(int i=0;i<arr.size();++i){
            total1+=temp[i];
            total2+=arr[i];
            if(total1==total2){
                answer++;
                total1=0;
                total2=0;
            }
        }
        return answer;
    }
};