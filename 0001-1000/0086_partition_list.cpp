// Problem 86: Partition List
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* greater_head=new ListNode(0),*g_next=greater_head,*less_head=new ListNode(0),*l_next=less_head;
        while(head!=nullptr){
            if(head->val>=x){
                g_next->next=new ListNode(head->val);
                g_next=g_next->next;
            }
            else{
                l_next->next=new ListNode(head->val);
                l_next=l_next->next;
            }
            head=head->next;
        }
        l_next->next=greater_head->next;
        return less_head->next;
    }
};