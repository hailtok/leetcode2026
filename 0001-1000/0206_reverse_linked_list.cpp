// Problem 206: Reverse Linked List
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=NULL;
        while(head!=NULL){
            ListNode* forward=head->next;
            head->next=temp;
            temp=head;
            head=forward;
        }
        return temp;
    }
};