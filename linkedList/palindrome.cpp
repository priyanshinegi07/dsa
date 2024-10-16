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

//brute force : push all elements to a stack and check while poping
//tc : O(2n) sc : O(n)

//optimal : reverse second half and check 
// tc : O(2n) sc : O(1) last n/2 tc is for reversing second half of linked list to get back original list
class Solution {
public:
    ListNode *middle(ListNode *head) {
        ListNode *s = head, *f = head;
        while(f -> next and f -> next -> next) {
            s = s -> next;
            f = f -> next -> next;
        }
        return s;
    }
    ListNode *reverse(ListNode * &node) {
        ListNode *p = NULL, *c = node, *n = NULL;
        while(c) {
            n = c -> next;
            c -> next = p;
            p = c;
            c = n;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        if(!head or !head -> next) return 1;
        ListNode *mid = middle(head);
        ListNode *s = reverse(mid -> next);
        // cout<<mid -> next -> val<<endl;
        
        // ListNode *s = p;
        // mid -> next = s;
        // while(s) {
        //     cout<<s -> val<<" ";
        //     s = s->next;
        // }cout<<endl;
        ListNode *temp = head;
        while(s) {
            // cout<<s -> val<<" "<<temp -> val<<endl;
            if(s -> val != temp -> val) return false;
        
            s = s-> next;
            temp = temp -> next;
            cout<<s<<" "<<temp<<endl;
        }
        return true;
        
    }
};