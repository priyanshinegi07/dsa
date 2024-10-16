// we cannot delete a node if head is not given because we cannot get the previous node, so we change the val of node and make it point to next to next element
// TC : O(1) SC : O(1)
void deleteNode(ListNode* node) {

        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }