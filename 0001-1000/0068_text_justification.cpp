// Problem 68: Text Justification
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/text-justification/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        string temp(maxWidth,' ');
        queue<string>que;
        for(int i=0,least_space=-1,cur=0;i<words.size();++i){
            if(cur+words[i].size()+least_space+1>maxWidth){
                int remain_space=maxWidth-cur,start=0;
                while(!que.empty()){
                    string b=que.front();
                    for(int j=0;j<b.size();++j){
                        temp[start+j]=b[j];
                    }
                    int re=least_space==0?0:remain_space/least_space;
                    if(least_space!=0&&remain_space%least_space!=0){
                        ++re;
                    }
                    start+=que.front().size()+re;
                    que.pop();
                    remain_space-=re;
                    --least_space;
                }
                ans.push_back(temp);
                string a(maxWidth,' ');
                temp=a;
                que.push(words[i]);
                cur=words[i].size();
                least_space=0;
            }
            else{
                ++least_space;
                cur+=words[i].size();
                que.push(words[i]);
            }
        }
        string last="";
        while(!que.empty()){
            last+=que.front();
            que.pop();
            if(!que.empty()){
                last+=' ';
            }
        }
        for(int i=last.size();i<maxWidth;++i){
            last+=' ';
        }
        ans.push_back(last);
        return ans;
    }
};