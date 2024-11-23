#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool can_place_cows(vector<int>&stalls, int cows, int min_dist) {
	int cnt = 1, last_pos = 0;
	for(int i = 1; i < stalls.size(); i++) {
		if(stalls[i] - stalls[last_pos] >= min_dist) {
			cnt++;
			last_pos = i;
			if(cnt == cows) return true;
		}
		
	}
	return false;
}
// TC : O(nlogn + log(min-max)*n)
int largest_min_dist(vector<int>&stalls, int c) {
	sort(stalls.begin(), stalls.end());
	int ans = 0;
	int n = stalls.size();
	int s = 1, e = stalls[n - 1] - stalls[0];
	while(s <= e) {
		int mid = (s + e) / 2;
		if(can_place_cows(stalls, c, mid)) {
			ans = mid;
			s = mid + 1;
		}
		else { 
			e = mid - 1;
		}
	}
	return ans;
	
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--) {
		int n, c;
		cin>>n>>c;
		vector<int>stalls(n);
		for(int i = 0; i < n; i++) {
			cin>>stalls[i];
		}
		cout<<largest_min_dist(stalls, c)<<endl;
	}
	
	return 0;
}