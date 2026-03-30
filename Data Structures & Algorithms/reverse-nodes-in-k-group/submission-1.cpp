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
    ListNode* reverseKGroup(ListNode* start, int k) {
        if(start == nullptr) return nullptr;
        ListNode* temp = start;
        ListNode* kth = temp;
        for(int i = 0; i < k; i++){
            if(kth == nullptr) return start;
            kth = kth -> next;
        }
        ListNode* prev = kth;
        while(temp != kth){
            ListNode* currNode = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = currNode; 
        }
        start -> next = reverseKGroup(kth, k);
        return prev;
    }
};
