// Problem 2487: Remove Nodes From Linked List
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/remove-nodes-from-linked-list/

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int>stack;
        ListNode dummy=ListNode();
        ListNode* tail=&dummy;
        ListNode* ptr=NULL;
        for (ListNode* curr=head; curr; curr = curr->next, delete ptr) {
            int cur_val = curr->val;
            ListNode* ptr=curr;
            while (!stack.empty() && (stack.back()<cur_val)){
                stack.pop_back();
            }
            stack.push_back(cur_val);
        }
        for(int i=0;i<stack.size();++i) {
            tail->next = new ListNode(stack[i]);
            tail=tail->next;
        }
        return dummy.next;
    }
};