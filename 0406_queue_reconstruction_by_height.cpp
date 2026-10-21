// Problem 406: Queue Reconstruction by Height
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/queue-reconstruction-by-height/

class Solution {
public:
    static bool cmp(vector<int>& p1, vector<int>& p2){
        if(p1[0]!=p2[0]) return p1[0]<p2[0];
        else return p1[1]>p2[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<int>bits=vector<int>(people.size()+1);
        for(int i=2;i<=people.size();++i){
            update(bits,i,1);
        }
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> answer(people.size(), vector<int>());
        for(int i=0;i<people.size();i++){
            int left=0,right=people.size();
            while(left<right){
                int mid=left+(right-left)/2;
                if(getsum(bits,mid+1)<people[i][1]){
                    left=mid+1;
                }
                else{
                    right=mid;
                }
            }
            answer[left]=people[i];
            update(bits,left+1,-1);
        }
        return answer;        
    }
    void update(vector<int>&bits,int x,int d){
        for(int i=x;i<bits.size();i+=(i&-i)){
            bits[i]+=d;
        }
    }
    int getsum(vector<int>&bits,int x){
        int sum=0;
        for(int i=x;i>0; i-=(i&-i)){
            sum+=bits[i];
        }
        return sum;
    }
};