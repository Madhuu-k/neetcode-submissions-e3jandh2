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
    bool hasCycle(ListNode* start) {
        ListNode* ft = start;
        ListNode* sl = start;
        while(ft && ft -> next ){
            sl = sl -> next;
            ft = ft -> next -> next;
            if(sl == ft) return true;
        }
        return false;
    }
};
