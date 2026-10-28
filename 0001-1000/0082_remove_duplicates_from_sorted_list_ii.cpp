// Problem 82: Remove Duplicates from Sorted List II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
        ListNode *newhead=new ListNode(-1,head),*temp=newhead->next,*pre=newhead;
        bool check=false;
        while(temp!=NULL&&temp->next!=NULL){
            if(temp->val!=temp->next->val){
                if(check){
                    check=false;
                }
                else{
                    pre->next=temp;
                    pre=temp;
                }
            }
            else{
                check=true;
            }
            temp=temp->next;
        }
        if(!check){
            pre->next=temp;
            pre=temp;
        }
        pre->next=NULL;
        return newhead->next;
    }
};