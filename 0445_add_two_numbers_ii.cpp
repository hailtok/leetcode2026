// Problem 445: Add Two Numbers II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/add-two-numbers-ii/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stack1,stack2;
        ListNode* answer=new ListNode(0);
        while(l1!=nullptr){
            stack1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=nullptr){
            stack2.push(l2->val);
            l2=l2->next;
        }
        bool check=false;
        while(true){
            int val=stack1.top()+stack2.top();
            if(check){
                check=false;
                val++;
            }
            if(val>=10){
                check=true;
                val-=10;
            }
            stack1.pop();
            stack2.pop();
            answer->val=val;
            if(!stack1.empty()&&!stack2.empty()){
                ListNode* temp=new ListNode(0);
                temp->next=answer;
                answer=temp;
            }
            else{
                break;
            }
        }
        while(!stack1.empty()){
            ListNode* temp=new ListNode(stack1.top()+check);
            if(temp->val>=10){
                temp->val-=10;
                check=true;
            }
            else{
                check=false;
            }
            stack1.pop();
            temp->next=answer;
            answer=temp;
        }
        while(!stack2.empty()){
            ListNode* temp=new ListNode(stack2.top()+check);
            if(temp->val>=10){
                temp->val-=10;
                check=true;
            }
            else{
                check=false;
            }
            stack2.pop();
            temp->next=answer;
            answer=temp;
        }
        if(check){
            ListNode* temp=new ListNode(1);
            temp->next=answer;
            answer=temp;
        }
        return answer;
    }
};