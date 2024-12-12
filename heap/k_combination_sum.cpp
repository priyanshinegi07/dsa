vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<pair<int, pair<int, int>>>pq;
    pq.push({A.back() + B.back(), {A.size() - 1, B.size() - 1}});
    set<pair<int, int>>s;
    s.insert({A.size() - 1, B.size() - 1});
    vector<int>ans;
    while(C--) {
        auto front = pq.top();
        int sum = front.first;
        int i = front.second.first;
        int j = front.second.second;
        ans.push_back(sum);
        pq.pop();
        if(s.find({i - 1, j}) == s.end()){
            pq.push({A[i - 1] + B[j], {i - 1, j}});
            s.insert({i - 1, j});
        }
        if(s.find({i, j - 1}) == s.end()){
            pq.push({A[i] + B[j - 1], {i, j - 1}});
            s.insert({i, j - 1});
        }
    }
    return ans;
    
}
