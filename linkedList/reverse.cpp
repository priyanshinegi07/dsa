class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p = NULL, *c = head, *n = NULL;
        while(c) {
            n = c -> next;
            c -> next = p;
            p = c;
            c = n;
        }
        return p;
        
    }
};