// brute
//generate all subarrs and calculate the sum, three loops, like largest subarr sum
//TC : O(n^3) SC : O(1)

//below is the optimization of brute
// generate all subarrs and track length of each 
// sumarr which has sum == 0 we update the max_length
//instead of maintaining length we can write  j - i + 1
//TC : O(n^2) SC : O(1)

// int max_len = 0;
// for(int i = 0; i < n; i++) {
//     int sum = arr[i], curr_len = 0;
//     for(int j = i; j < n; j++) {
//         curr_len++;
//         if(i == j) continue;
//         sum += arr[j];
//         if(!sum) {
//             max_len = max(curr_len, max_len);
//         }
//     }return max_len;
// }

//better
// this is the optimal for arr having 0 and -ve nos
//if till a current pt we have sum x and we check if previously we had sum-k then definitely we have k sum in the current subarr
//so we update the max_len
//we take a prefix sum in hashmap and store the index
//if we have 0 in arr, then we have the consider the largest length and we take the leftmost remaining sum, therefore, we do not update the map if we already had sum in it, coz we have consider the leftmost index where this sum is present so as to have the longest arr
// TC : O(n) SC : O(n) - we store sum of n indices, every individual index will have unique prefix sum, in case of -ve and 0 it may repeat

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        map<int, int>mp;
        int k = 0;
        long long sum = 0; 
        int max_len = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(sum == k) {
                max_len = max(max_len, i+1);
            }
            long long rem = sum - k;
            if(mp.find(rem) != mp.end()) {
                max_len = max(max_len, i - mp[sum-k]);
            }
            //if 0 occured then we have to see the leftmost index where sum-k is present and therefore
            // we do not update index if sum - k is  already present
            if(mp.find(rem) == mp.end())
                mp[sum] = i;
        }
        return max_len;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}


//optimal sol(for arr with 0 and pos no only)
//as we move right the sum will definitely increase
//2ptrs, we take the right ptr till the sum < k, if it exceed k we reduce sum by removing the element at left
//TC : O(2n) SC : O(1) inner while loop runs max n times in total not for each  outer iteration
long long sum = a[i]//initially sum will be first element
int left = 0, right = 0, len = 0;
while(right < n) {
    while(left <= right and sum > k) {
        sum -= a[left];
        left++;
    }
    if(sum == k) {
        len = max(len, right - left + 1);
    }
    right++;
    if(right < n) {
        
        sum += a[right];
    }
    return len;

}
