//copy all the nodes and create new nodes
//put all the original and copy nodes in map
//traverse the list again and connect the next and random ptrs
//TC : O(2n) SC : O(n for map + n for nodes but this is reqd in ques)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        map<Node*, Node*>mp;
        Node *temp = head;
        while(temp) {
            Node *new_node = new Node(temp -> val);
            mp[temp] = new_node;
            temp = temp -> next; 
        }
        // mp[0] = 0;
        temp = head;
        cout<<temp -> val<<endl;
        // for(auto val : mp) {
        //     cout<<val.first<<" "<<val.second<<endl;
        // }
        while(temp) {
            Node *copy_node = mp[temp];
            // cout<<mp[temp]<<"p"<<mp[temp -> next]<<endl;
            if(!temp -> next) copy_node -> next = 0;
            else copy_node -> next = mp[temp -> next];
            if(!temp -> random) copy_node -> random = 0;
            copy_node -> random = mp[temp -> random];
            temp = temp -> next;
        }
        return mp[head];
    }
};

//insert copy nodes in between
//connect random ptrs
//connect next ptrs
// TC : O(2n) SC : O(n for nodes which is reqd in ques)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node *temp = head;
        //insert new nodes between original nodes
        while(temp) {
            Node *new_node = new Node(temp -> val);
            new_node -> next = temp -> next;
            temp -> next = new_node;
            temp = new_node -> next;
        }
        //connect random ptr
        temp = head;
        while(temp) {
            temp -> next -> random = temp -> random ? temp -> random -> next : 0;
            temp = temp -> next -> next;
        }

        //connect next ptrs
        temp = head;
        Node *new_head = temp -> next;
        Node *res = new_head;
        while(temp) {
            cout<<temp -> val<<endl;
            temp -> next = temp -> next -> next;
            if(!temp -> next) res -> next = 0;
            else res -> next = temp -> next -> next;
            temp = temp -> next;
            res = res -> next;

        }
        return new_head;


    }
};