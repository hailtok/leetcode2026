// Problem 19: Remove Nth Node From End of List
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int depth=0;
        ListNode* temp=head;
        while(temp!=NULL){
            depth++;
            temp=temp->next;
        }
        if(depth==1){
            return NULL;
        }
        temp=head;
        ListNode* pre=NULL,*last=NULL;
        while(depth-n>0){
            pre=temp;
            last=temp->next->next;
            temp=temp->next;
            depth--;
        }
        if(pre==NULL){
            return head->next;
        }
        else{
            pre->next=last;
        }

        return head;
    }
};