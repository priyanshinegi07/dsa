#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    vector<int> hor_cost = {1, 2, 4, 1, 3};
    vector<int> ver_cost = {4, 1, 2};
    sort(hor_cost.begin(), hor_cost.end(), greater<int>());
    sort(ver_cost.begin(), ver_cost.end(), greater<int>());
    int h = 0, v = 0;
    int hp = 1, vp = 1;
    int cost = 0;
    while(h < hor_cost.size() && v < ver_cost.size()) {
        if(hor_cost[h] > ver_cost[v]) {//horizontal cut
            cost += (hor_cost[h] * vp);
            hp++;
            h++;

        }
        else {
            cost += (ver_cost[v] * hp);
            vp++;
            v++;
        }
    }
    while(h < hor_cost.size()) {
        cost += hor_cost[h] * vp;
        hp++;
        h++;
    }
    while(v < ver_cost.size()) {
        cost += ver_cost[v] * hp;
        vp++;
        v++;
    }
    // cout<<vp<<" "<<hp<<endl;
    
    cout<<cost<<endl;
    // cout<<"hello"<<endl;
    return 0;
}