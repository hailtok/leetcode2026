// Problem 902: Numbers At Most N Given Digit Set
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int>nums;
        for(int i=0;i<digits.size();++i){
            nums.push_back(digits[i][0]-'0');
        }
        int digits_count=0;
        vector<int>reverse;
        while(n>0){
            reverse.push_back(n%10);
            ++digits_count;
            n/=10;
        }
        int ans=0;
        for(int i=0,base=digits.size(),count=1;i<digits_count-1;++i){
            count*=base;
            ans+=count;
        }
        bool check=true;
        int total=0,index=reverse.size()-1,base=1;
        while(index>=0){
            int pos=lower_bound(nums.begin(),nums.end(),reverse[index])-nums.begin();
            total+=pos*std::pow(digits.size(),index);
            if(pos<nums.size()&&nums[pos]==reverse[index]){
                --index;
            }
            else{
                break;
            }
        }
        if(index<0){
            ++total;
        }
        return ans+total;
    }
};