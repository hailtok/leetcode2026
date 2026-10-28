// Problem 237: Delete Node in a Linked List
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/delete-node-in-a-linked-list/

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
    void deleteNode(ListNode* node) {
        int temp=node->val;
        while(true){
            temp=node->next->val;
            node->val=temp;
            if(node->next->next==NULL){
                node->next=NULL;
                break;
            }
            node=node->next;
        }

    }
};