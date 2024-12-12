void insert(int d, vector<int>& v) {
    v.push_back(d);  
    int c = v.size() - 1;  
    int p = c / 2;  
    while (p > 0 && v[p] > v[c]) {  
        swap(v[p], v[c]);
        c = p;
        p = c / 2;
    }
}

void heapify(int i, vector<int>& v) {
    int lc = 2 * i;     
    int rc = 2 * i + 1;  
    int mi = i;
    
    if (lc < v.size() && v[lc] < v[mi]) mi = lc; 
    if (rc < v.size() && v[rc] < v[mi]) mi = rc;  
    if (mi != i) {  
        swap(v[mi], v[i]);
        heapify(mi, v);  
    }
}

void delete_from_heap(vector<int>& v) {
    swap(v[1], v[v.size() - 1]);  
    v.pop_back();  
    heapify(1, v);  
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> min_heap; 
    vector<int> ans;
    min_heap.push_back(INT_MIN);// if we check for child in insert operation, c > 1 then we donot have to place a dummy value at 0th index
    for (auto query : q) {
        if (query[0] == 0) {  
            insert(query[1], min_heap);
        } else {  
            ans.push_back(min_heap[1]);  
            delete_from_heap(min_heap);  
        }
    }
    return ans;
}
