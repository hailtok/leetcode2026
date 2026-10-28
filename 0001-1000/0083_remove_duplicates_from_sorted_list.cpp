// Problem 83: Remove Duplicates from Sorted List
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return head;
        }
        int value=head->val;
        ListNode* pre=head,*temp=head->next;
        while(temp!=NULL){
            if(temp->val!=value){
                value=temp->val;
                pre->next=temp;
                pre=temp;
            }
            temp=temp->next;
        }
        pre->next=NULL;
        return head;
    }
};