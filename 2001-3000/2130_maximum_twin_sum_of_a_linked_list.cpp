// Problem 2130: Maximum Twin Sum of a Linked List
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

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
    ListNode* reverse(ListNode* head){
        ListNode*front=head->next;
        ListNode*prev=nullptr;
        while(head){
            front=head->next;
            head->next=prev;
            prev=head;
            head=front;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow=reverse(slow->next);
        int answer=0;
        while(slow){
            answer=std::max(answer,slow->val+head->val);
            slow=slow->next;
            head=head->next;
        }
        return answer;
    }
};








class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>value;
        int answer=0;
        while(head){
            value.push_back(head->val);
            head=head->next;
        }
        for(int i=0;i<value.size()/2;++i){
            answer=std::max(answer,value[i]+value[value.size()-1-i]);
        }
        return answer;
    }
};