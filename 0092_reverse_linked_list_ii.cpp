// Problem 92: Reverse Linked List II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* answer=head,*left_node=NULL,*temp=NULL,*right_node=head;
        for(int i=1;i<left;i++){
            left_node=head;
            head=head->next;
            right_node=head;
        }
        for(int i=left-1;i<right;i++){
            ListNode* forward=head->next;
            head->next=temp;
            temp=head;
            head=forward;
        }
        if(right_node!=NULL){
        cout<<right_node->val<<endl;
            right_node->next=head;
        }
        if(left_node!=NULL){
            left_node->next=temp;
            cout<<temp->val<<endl;
            return answer;
        }
        return temp;
    }
};