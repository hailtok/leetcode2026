// Problem 2: Add Two Numbers
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        ListNode* answer=new ListNode();
        ListNode* temp=answer;
        while(l1!=NULL||l2!=NULL){
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            sum/=10;
        }
        if(sum==1){
            temp->next=new ListNode(1);
        }
        return answer->next;
    }
};