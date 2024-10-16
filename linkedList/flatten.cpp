//brute force : we convert linked list into arr, then sort the again and again create linked list from it
// TC : O(2(mn) + xlogx) m, n are the vertical and horizontal length respectively and x = n*m
// SC : O(2(mn)) first time for creating arr, second time for creating linked list

//optimal : we start by flattening the last two linked list and then recursively merge all list
// TC : O(2mn) SC : O(n) which is stack space for recursion
//we are not using extra time for sorting as lists are vertically sorted
class Solution {
  public:
  Node * merge_ll(Node* l1, Node* l2) {
      Node* dummy = new Node(0);
      Node* temp = dummy;
      while(l1 and l2) {
          if(l1 -> data < l2 -> data) {
              temp -> bottom = l1;
              temp = l1;
              l1 = l1 -> bottom;
          }else{
              temp -> bottom = l2;
              temp = l2;
              l2 = l2 -> bottom;
          }
        //   temp -> next = NULL;
      }
      if(l1) temp -> bottom = l1;
      else temp -> bottom = l2;
      return dummy -> bottom;
  }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        //base case
        if(!root or !(root -> next)) return root;
        //recursive case
        Node * merged_head = flatten(root -> next);
        return merge_ll(root, merged_head);
    }
};