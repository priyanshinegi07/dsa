#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    void f(vector<int>arr, vector<int>&ans, int n, int i, int sum) {
        //base case
        if(n == i) {
            ans.push_back(sum);
            return;
        }
        //recursive case
        
        //choose current element
        sum += arr[i];
        f(arr, ans, n, i + 1, sum);
        
        //do not choose current element
        sum -= arr[i];
        f(arr, ans, n, i + 1, sum);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int>ans;
        int sum = 0;
        f(arr, ans, n, 0, sum);
        return ans;
    }
};
