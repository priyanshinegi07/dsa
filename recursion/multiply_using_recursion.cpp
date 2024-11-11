#include<iostream>
using namespace std;
int product(int m, int n) {
    int ans = 0;
    //base case
    if(n == 0) return 0;
    //recursive case
    ans += m + product(m, n-1);
    return ans;
    
}
int main() {
    int m = 2, n = 19;
    int ans = 0;
    cout<<product(m, n);
    // cout<<ans<<endl;
    return 0;
}
  

