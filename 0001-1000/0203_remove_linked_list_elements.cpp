// Problem 203: Remove Linked List Elements
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre=head,*cur=head==nullptr?nullptr:head->next,*ans=head;
        while(pre!=nullptr&&cur!=nullptr){
            if(cur->val==val){
                pre->next=cur->next;
                cur=cur->next;
            }
            else{
                pre=pre->next;
                cur=cur->next;
            }
        }
        if(ans!=nullptr&&ans->val==val){
            return ans->next;
        }
        return ans;
    }
};