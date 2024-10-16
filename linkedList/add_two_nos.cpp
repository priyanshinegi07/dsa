#include<iostream>
using namespace std;


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1, *h2 = l2;
        int sum = 0, carry = 0;
        ListNode *new_head = new ListNode();
        ListNode *prev = new_head;
        
        while(h1 && h2) {
            ListNode* curr = new ListNode();
            prev -> next = curr;
            sum = h1 -> val + h2 -> val + carry;
            if(sum > 9) {
                //carry is first digit and sum is last digit in this case
                carry = sum/10;
                curr -> val = sum%10;
            }
            else {
                curr -> val = sum;
                carry = 0;
            }
            prev = curr;
            h1 = h1 -> next;
            h2 = h2 -> next;
            if(!h1 and !h2 && carry) {
                prev -> next = new ListNode(carry);
            }
        }
        while(h1) {
            ListNode* curr = new ListNode();
            prev -> next = curr;
            sum = h1 -> val + carry;
            if(sum > 9) {
                carry = sum/10;
                curr -> val = sum%10;
            }
            else {
                curr -> val = sum;
                carry = 0;
            }
            prev = curr;
            h1 = h1 -> next;
            if(!h1 && carry) {
                prev -> next = new ListNode(carry);
            }
        }

        while(h2) {
            ListNode* curr = new ListNode();
            prev -> next = curr;
            sum = h2 -> val + carry;
            if(sum > 9) {
                carry = sum/10;
                curr -> val = sum%10;
            }
            else {
                curr -> val = sum;
                carry = 0;
            }
            prev = curr;
            h2 = h2 -> next;
            if(!h2 && carry) {
                prev -> next = new ListNode(carry);
            }

        }
        // if(carry) {
        //     ListNode* curr = new ListNode(carry);
        //     prev -> next = curr;

        // }
        return new_head -> next;
    }