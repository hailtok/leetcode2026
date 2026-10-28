// Problem 25: Reverse Nodes in k-Group
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/reverse-nodes-in-k-group/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre=new ListNode(0);
        ListNode* ans=pre;
        while(head!=nullptr){
            ListNode* head2=head;
            stack<int>stack;
            for(int i=0;i<k&&head!=nullptr;++i){
                stack.push(head->val);
                head=head->next;
            }
            if(stack.size()!=k){
                pre->next=head2;
                break;
            }
            ListNode* temp=new ListNode(stack.top());
            stack.pop();
            ListNode* temp_head=temp;
            while(!stack.empty()){
                temp->next=new ListNode(stack.top());
                temp=temp->next;
                stack.pop();
            }
            pre->next=temp_head;
            pre=temp;
        }
        return ans->next;
    }
};