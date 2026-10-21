// Problem 23: Merge k Sorted Lists
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/merge-k-sorted-lists/

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
 struct cmp {
    bool operator()(ListNode* left,ListNode* right) {
        return left->val>right->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        for(int i=0;i<lists.size();++i){
            if(lists[i]!=nullptr){
                pq.push(lists[i]);
            }
        }
        ListNode* ans=new ListNode(0);
        ListNode* top=ans;
        while(!pq.empty()){
            cout<<pq.top()->val<<endl;
            ans->next=new ListNode(pq.top()->val);
            ans=ans->next;
            ListNode* temp=pq.top()->next;
            pq.pop();
            if(temp!=nullptr){
                pq.push(temp);
            }
        }
        return top->next;
    }
};