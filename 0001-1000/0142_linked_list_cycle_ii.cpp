// Problem 142: Linked List Cycle II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr){
            return nullptr;
        }
        ListNode *slow=head,*fast=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                while(head!=slow){
                    head=head->next;
                    slow=slow->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};