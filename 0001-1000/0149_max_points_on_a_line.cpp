// Problem 149: Max Points on a Line
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/max-points-on-a-line/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=1){
            return points.size();
        }
        set<pair<double,double>>lines;
        set<int>x;
        for(int i=0;i<points.size();++i){
            for(int j=i+1;j<points.size();++j){
                if(points[i][0]==points[j][0]){
                    x.insert(points[i][0]);
                    continue;
                }
                double a=(double)(points[i][1]-points[j][1])/(double)(points[i][0]-points[j][0]),
                b=points[i][1]-points[i][0]*a;
                lines.insert({a,b});
            }
        }
        int ans=0;
        for(auto it=lines.begin();it!=lines.end();++it){
            int count=0;
            for(int i=0;i<points.size();++i){
                if(std::abs(it->first*points[i][0]+it->second-points[i][1])<1e-6){
                    ++count;
                }
            }
            ans=std::max(ans,count);
        }
        for(auto it=x.begin();it!=x.end();++it){
            int count=0;
            for(int i=0;i<points.size();++i){
                if(*it==points[i][0]){
                    ++count;
                }
            }
            ans=std::max(ans,count);
        }
        return ans;
    }
};