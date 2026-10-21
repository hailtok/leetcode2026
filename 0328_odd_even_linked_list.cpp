// Problem 328: Odd Even Linked List
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode*odd=head,*even=head->next,*temp=head->next->next,*even_head=even;
        int depth=1;
        while(temp!=NULL){
            if(depth%2){
                odd->next=temp;
                odd=temp;
                even->next=NULL;
            }
            else{ 
                even->next=temp;
                even=temp;
                odd->next=NULL;
            }
            depth++;
            temp=temp->next;
        }
        odd->next=even_head;
        return head;
    }
};