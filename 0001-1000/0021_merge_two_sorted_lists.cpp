// Problem 21: Merge Two Sorted Lists
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* answer=new ListNode();
        ListNode* head=answer;
        while(list1!=NULL&&list2!=NULL){
            answer->next=new ListNode();
            answer=answer->next;
            if(list1->val>list2->val){
                answer->val=list2->val;
                list2=list2->next;
            }
            else{
                answer->val=list1->val;
                list1=list1->next;
            }
        }
        if(list1!=NULL){
            while(list1!=NULL){
                answer->next=new ListNode();
                answer=answer->next;
                answer->val=list1->val;
                list1=list1->next;
            }
        }
        else{
            while(list2!=NULL){
                answer->next=new ListNode();
                answer=answer->next;
                answer->val=list2->val;
                list2=list2->next;
            }
        }
        return head->next;
    }
};