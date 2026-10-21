// Problem 93: Restore IP Addresses
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/restore-ip-addresses/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<int>numbers(3);
        vector<string>output;
        int size=int(pow(3,3));
        for(int i=0;i<size;i++){
            if(s.size()-numbers[0]-numbers[1]-numbers[2]<=6&&s.size()-numbers[0]-numbers[1]-numbers[2]>=4){
                string answer="";
                for(int j=0;j<s.size();j++){
                    if(j==numbers[2]+1||j==numbers[2]+numbers[1]+2||j==numbers[2]+numbers[1]+numbers[0]+3){
                        answer.push_back('.');
                    }
                    answer.push_back(s[j]);
                }
                if(check_ip(answer).size()==answer.size()){
                    output.push_back(answer);
                }
            }
            numbers[0]=(numbers[0]+(numbers[1]+(numbers[2]+1)/3)/3)%3;
            numbers[1]=(numbers[1]+(numbers[2]+1)/3)%3;
            numbers[2]=(numbers[2]+1)%3;
        }
        return output;
    }
    string check_ip(string IP){
        int temp=0;
        string new_IP="";
        for(int i=0;i<IP.size();i++){
            if(isdigit(IP[i])){
                temp=temp*10+IP[i]-'0';
            }
            else{
                if(temp>255){
                    return "";
                }
                else{
                    new_IP+=to_string(temp)+".";
                    temp=0;
                }
            }
        }
        if(temp>255){
            return "";
        }
        new_IP+=to_string(temp);
        return new_IP;
    }
};