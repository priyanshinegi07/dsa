#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<int>coins = {2000, 500, 100, 5, 2, 1, 10, 100, 20, 50};
    sort(coins.begin(), coins.end(), greater<int>());
    int cnt = 0, amt = 590;
    for(int i = 0; i < coins.size(); i++) {
        while(coins[i] <= amt) {
            cnt++;
            amt -= coins[i];
            cout<<coins[i]<<" ";
        }
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
}