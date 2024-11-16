// TC : n * (log(m)) for log(m) iterations we are running n loop for multiplying

int multiple(int mid, int n) {
    long long ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= mid;
        if(ans > INT_MAX) return INT_MAX;
    }
    return ans;
}
int NthRoot(int n, int m) {
  // Write your code here.
    // int sq_root = pow(m, 0.5);
    // int sq_root = pow(m, 0.5);
    int s = 1, e = m;
    // cout<<e<<" ";
    while(s <= e) {
        int mid = (s+e)/2;
        int x = multiple(mid, n);
        if(x == m) {
            return mid;
        }
        else if(x > m) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return -1;
}