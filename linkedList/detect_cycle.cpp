//brute : use hash table and store every node you visit while traversing
//push the node in hash table if it is not present, if the node is already present the there is a cycle
//TC : O(n) SC : O(n)

//optimal : slow and fast

bool hasCycle(ListNode *head) {
        if(!head or !head -> next) return 0;
        ListNode *s = head, *f = head;
        
        while(f and f -> next) {
            s = s -> next;
            f = f -> next -> next;
            //if s and f are equal then definitely there is cycle so we don't even have to return 0 and null dosen't even
            //exist in the list
            // if(s == f) return s ? s -> next : 0;
            //above statement also works
            if(s == f) return true;
            
            
        }
        
        return 0;

    }