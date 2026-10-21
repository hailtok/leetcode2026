// Problem 24: Swap Nodes in Pairs
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        ListNode* answer=head->next;
        while(head!=NULL&&head->next!=NULL){
            ListNode* forward=head->next;
            temp->next=forward;
            head->next=forward->next;
            forward->next=head;
            temp=head;
            head=head->next;
        }
        return answer;
    }
};