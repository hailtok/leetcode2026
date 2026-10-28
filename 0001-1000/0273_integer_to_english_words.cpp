// Problem 273: Integer to English Words
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/integer-to-english-words/

class Solution {
public:
    vector<string>umap1={"Billion","Million","Thousand"};
    unordered_map<int,string>umap3={{2,"Twenty"},{3,"Thirty"},{4,"Forty"},{5,"Fifty"},{6,"Sixty"},{7,"Seventy"},{8,"Eighty"},{9,"Ninety"}};
    unordered_map<int,string>umap4={{10,"Ten"},{11,"Eleven"},{12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},{15,"Fifteen"},{16,"Sixteen"},{17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"}};
    unordered_map<int,string>umap5={{1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},{6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"}};
    string num_to_string(int num){
        cout<<num<<endl;
        if(num==0){
            return "";
        }
        string output="";
        if(num>=100){
            output+=umap5[num/100]+" Hundred ";
            num%=100;
        }
        if(num>=20){
            output+=umap3[num/10]+" ";
            num%=10;
        }
        else if(num>=10){
            output+=umap4[num]+" ";
            return output;
        }
        if(num!=0){
            output+=umap5[num]+" ";
        }
        return output;
    }
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
        string answer="";
        int temp=1000000000;
        for(int i=0;i<umap1.size();++i){
            if(num>=temp){
                answer+=num_to_string(num/temp)+umap1[i]+" ";
                num%=temp;
            }
            temp/=1000;
        }
        if(num>=100){
            answer+=umap5[num/100]+" Hundred ";
            num%=100;
        }
        if(num>=20){
            answer+=umap3[num/10]+" ";
            num%=10;
        }
        else if(num>=10){
            answer+=umap4[num];
            return answer;
        }
        answer+=umap5[num];
        if(answer.back()==' '){
            answer.pop_back();
        }
        return answer;
    }
};