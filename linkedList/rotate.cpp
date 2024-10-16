//this is my approach 
//i solved in similar way as we rotate arr
// TC : O(n) TC : O(1)
class Solution {
public:
    int length(ListNode *head) {
        int cnt = 0;
        while(head) {
            cnt++;
            head = head -> next;
        }
        return cnt;
    } 
    ListNode *reverse(ListNode *head) {
        if(!head or !head -> next) return head;
        ListNode *p = 0, *c = head, *n = 0;
        while(c) {
            n = c -> next;
            c -> next = p;
            p = c;
            c = n;
            // cout<<p<<endl;
        }
        // cout<<p -> val<<endl;
        return p;
    }
    ListNode * find_kth_node(ListNode *head, int k) {
        k--;
        while(head and k) {
            head = head -> next;
            k--;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = length(head);
        if(!len) return head;
        k %= len;
        if(!k or !head or !head -> next) return head;
        ListNode *temp = head, *first_node = NULL, *kth_node = NULL, *n = NULL;
        
        first_node = reverse(temp);
        cout<<"1"<<first_node -> val<<endl;
        kth_node = find_kth_node(first_node, k);
        cout<<"!"<<kth_node -> val<<endl;
        n = kth_node -> next;
        //reverse first 
        kth_node -> next = 0;
        ListNode *nh = reverse(first_node);
        // reverse(next);
        first_node -> next = reverse(n);
        return nh;

    }
};

//optimal and nice approach
//as after rotating the last node is connected to head, so we make a tail pointer and connect it to head
//if we rotate by two then third node will be head because last two will come at front
//so we traverse and get the third node, next ptr of third will be new head and third -> next = 0
//TC : O(n - k%n) SC : O(1)

class Solution {
public:
    int length(ListNode * head) {
        int len = 0;
        while(head) {
            len++;
            head = head -> next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !k) return head;
        int len = length(head);
        
        if(!(k % len)) return head;
        ListNode * tail = head;
        while(tail ->next) {
            tail = tail -> next;// can do len++ here only to get the len, no need of separate func
        }
        tail -> next = head;
        ListNode *temp = head;
        for(int i = 1; i < len - k%len; i++) {
            temp = temp -> next;
        }
        cout<<temp -> val<<endl;
        head = temp -> next;
        temp -> next = 0;
        return head;
    }
};