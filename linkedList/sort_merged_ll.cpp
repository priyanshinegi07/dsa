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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* h1 = list1, *h2 = list2, *c1 = h1, *c2 = h2;
        ListNode* n1 = c1 -> next, *n2 = c2 -> next, *nh = NULL, *p = NULL;
        while(c1 and c2) {
            if(c1 -> val <= c2 -> val and h1 == c1 and h2 == c2) {
                nh = c1;
                c1 = n1;
                if(n1) n1 = n1 -> next;
                p = nh;
            }
            else if(c1 -> val > c2 -> val and h1 == c1 and h2 == c2) {
                nh = c2;
                c2 = n2;
                if(n2) n2 = n2 -> next;
                p = nh;
            }
            else if(c1 -> val < c2 -> val) {
                p -> next = c1;
                p = c1;
                c1 = n1;
                if(n1) n1 = n1 -> next;
            }
            else if(c1 -> val > c2 -> val) {
                p -> next = c2;
                p = c2;
                c2 = n2;
                if(n2) n2 = n2 -> next;
            }
            else {
                p -> next = c1;
                p = c1;
                c1 = n1;
                if(n1) n1 = n1 -> next;
                p -> next = c2;
                p = c2;
                c2 = n2;
                if(n2) n2 = n2 -> next;

            }
        }
        if(c1) p -> next = c1;
        if(c2) p -> next = c2;
        return nh;
    }
};

//recursive approach
ListNode* merged_ll(ListNode* list1, ListNode* list2) {
        //base case
        if(!list1) return list2;
        if(!list2) return list1;
        //recursive case
        ListNode* nh = NULL;
        if(list1 -> val <= list2 -> val) {
            nh = list1;
            nh -> next = merged_ll(list1 -> next, list2);
        }
        else {
            nh = list2;
            nh -> next = merged_ll(list1, list2 -> next);
        }
        return nh;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // return merged_ll(list1, list2);
        //base case
        if(!list1) return list2;
        if(!list2) return list1;
        //recursive case
        ListNode* nh = NULL;
        if(list1 -> val <= list2 -> val) {
            nh = list1;
            nh -> next = mergeTwoLists(list1 -> next, list2);
        }
        else {
            nh = list2;
            nh -> next = mergeTwoLists(list1, list2 -> next);
        }
        return nh;
    }

//nice approach cb
void merge_2_sorted_ll(node * &h1, node * &h2){
	node * p1 = h1;
	node * p2 = h2;
	node * c = 0;
	if(p1 -> data <= p2 -> data){
		c = p1;
		// h2 = h1;
		p1 = p1 -> next;
	}else{
		c = p2;
		// h1 = h2;
		p2 = p2 -> next;
	}
	while(p1 and p2){
		if(p1 -> data <= p2 -> data){
			c -> next = p1;
			c = p1;
			p1 = p1 -> next;
		}else{
			c -> next = p2;
			c = p2;
			p2 = p2 -> next;
		}
	}
	if(p1){
		c -> next = p1;
		// t2 = t1;
	}else{
		c -> next = p2;
		// t1 = t2;
	}
}