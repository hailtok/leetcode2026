// Problem 165: Compare Version Numbers
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/compare-version-numbers/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ver1=0,ver2=0,i=0,j=0;
        while(i<version1.size()&&j<version2.size()){
            if(version1[i]=='.'){
                while(j<version2.size()){
                    if(version2[j]=='.'){
                        if(ver1>ver2){
                            return 1;
                        }
                        else if(ver1<ver2){
                            return -1;
                        }
                        else{
                            ++j;
                            ver1=0;
                            ver2=0;
                            break;
                        }
                    }
                    else{
                        ver2*=10;
                        ver2+=version2[j]-'0';
                        ++j;
                    }
                }
            }
            else{
                ver1*=10;
                ver1+=version1[i]-'0';
            }
            ++i;
        }
        while(j<version2.size()){
            if(version2[j]=='.'){
                break;
            }
            else{
                ver2*=10;
                ver2+=version2[j]-'0';
                ++j;
            }
            
        }
        if(ver1>ver2){
            return 1;
        }
        else if(ver1<ver2){
            return -1;
        }
        if(i<version1.size()){
            while(i<version1.size()){
                if(version1[i]!='.'&&version1[i]!='0'){
                    return 1;
                }
                ++i;
            }
        }
        else{
            while(j<version2.size()){
                if(version2[j]!='.'&&version2[j]!='0'){
                    return -1;
                }
                ++j;
            }
        }
        return 0;
    }
};