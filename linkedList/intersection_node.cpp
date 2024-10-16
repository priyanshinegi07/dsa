// brute : for every node in one linked list check for every other node in another linked list
//TC : O(m*n) SC : O(1) m, n is size of linked list
//Better : hash the addresses of all nodes in one linked list and check in another linked list whether the node has occurred in hash table or not
// TC : O(m + n) SC : O(m) or O(n)

//optimal
//TC : O(m+n) SC :O(1)

int length(ListNode* node) {
        int cnt = 0;
        while(node) {
            cnt++;
            node = node -> next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = length(headA), lenB = length(headB);
        int diff = abs(lenA - lenB);
        ListNode* lA = headA, *lB = headB;
        if(lenA > lenB) {
            while(diff--) lA = lA -> next;
        }
        else {
            while(diff--) lB = lB -> next;
        }
        while(lA && lB) {
            if(lA == lB) return lA;
            lA = lA -> next;
            lB = lB -> next;
        }
        return 0;
    }

//optimal 2
//TC : O(m + m-n + n)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA, *d2 = headB;
        while(d1 != d2) {
            d1 = d1 == NULL ? headB : d1 = d1 -> next;
            d2 = d2 == NULL ? headA : d2 = d2 -> next;
        }
        return d1;
    }