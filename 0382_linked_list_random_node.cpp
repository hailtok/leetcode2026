// Problem 382: Linked List Random Node
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/linked-list-random-node/

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
    ListNode* start;
    Solution(ListNode* head) {
        start=head;
    }
    
    int getRandom() {
        ListNode* node=start;
        int answer= node->val,depth=1;
        while(node){
            if(rand()%depth==0){
                answer=node->val;
            }
            depth++;
            node=node->next;
        }
        return answer;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */