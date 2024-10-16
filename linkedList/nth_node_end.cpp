//O(2n)
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int cnt = 0;
        ListNode* temp = head;
        while(temp) {
            cnt++;
            temp = temp -> next;
        }
        // if(cnt == 1 and n >= 1) return 0;
        if(n > cnt) return head;
        if(cnt == n) return head -> next;
        int pos = cnt - n; pos--;
        temp = head;
        // cout<<pos<<endl;
        while(pos--) {
            temp = temp -> next;
            // pos--;

        }
        temp -> next = temp -> next -> next;
        return head;

    }
};

//O(n)
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* f = head, *s = head;
        for(int i = 0; i < n; i++) {
            f = f -> next;
        }
        if(f == NULL) return head -> next;
        while(f -> next) {
            s = s -> next;
            f = f -> next;
        }
        s -> next = s -> next -> next;
        return head;
    }