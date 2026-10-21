// Problem 2181: Merge Nodes in Between Zeros
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/merge-nodes-in-between-zeros/

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
    ListNode* mergeNodes(ListNode* head) {
        head=head->next;
        if(head==nullptr){
            return head;
        }
        ListNode* temp=head;
        int val=0;
        while(temp->val!=0){
            val+=temp->val;
            temp=temp->next;
        }
        head->val=val;
        head->next=mergeNodes(temp);
        return head;
    }
};