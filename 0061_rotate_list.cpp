// Problem 61: Rotate List
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        int depth=0;
        ListNode* temp=head,*last_node=NULL,*answer=NULL;
        while(temp!=NULL){
            depth++;
            last_node=temp;
            temp=temp->next;
        }
        k=depth-k%depth-1;
        temp=head;
        while(k>0){
            temp=temp->next;
            k--;
        }
        last_node->next=head;
        answer=temp->next;
        temp->next=NULL;
        return answer;
    }
};