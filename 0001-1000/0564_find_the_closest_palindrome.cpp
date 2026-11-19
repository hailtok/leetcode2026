// Problem 564: Find the Closest Palindrome
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/find-the-closest-palindrome/

class Solution {
public:
    long long generatePalindrome(string &s,int len){
        long long prefix=stoll(s);
        long long res=prefix;
        int n=len/2;
        if(len%2!=0){
            prefix/=10;
        }
        while(prefix>0) {
            res=res*10+(prefix%10);
            prefix/=10;
        }
        return res;
    }
    string nearestPalindromic(string n) {
        int len=n.length();
        unsigned long long num=stoull(n);
        unordered_set<unsigned long long>candidates;
        if (len>1) {
            candidates.insert(stoull(string(len-1,'9')));
        }
        string s2(len+1,'0');
        s2[0]='1';
        s2[len]='1';
        candidates.insert(stoull(s2));
        int mid=(len+1)/2;
        string origPrefix=n.substr(0,mid);
        unsigned long long prefixNum=stoull(origPrefix);
        for(long long d:{-1,0,1}) {
            if(prefixNum==0&&d==-1){
                continue;
            }
            string pStr=to_string(prefixNum+d);
            if(pStr.length()==origPrefix.length()) {
                candidates.insert(generatePalindrome(pStr,len%2!=0));
            }
        }
        candidates.erase(num);
        unsigned long long nearest=0;
        unsigned long long minDiff=ULLONG_MAX;
        for(unsigned long long cand:candidates){
            unsigned long long diff=(cand>num)?(cand-num):(num-cand);
            if (diff<minDiff||(diff==minDiff&&cand<nearest)) {
                minDiff=diff;
                nearest=cand;
            }
        }
        return to_string(nearest);
    }
};