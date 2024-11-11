// tc : O(2^n * k) saare combination generate krenge and ek combination to ans mei daalne ke liye k(avg length) time lgega
// sc : O(k * x) x is no of combinations
// if we do not optimize and use set then tc will have klog(no of elements in set/set size) instead of k, insertion in ordered set takes logn time
class Solution {
public:
    void generate_combinations(vector<int>&candidates, int n, int target, vector<vector<int>>&ans, vector<int>&curr, int i, int &sum, bool check) {
        //base case
        if(i == n) {
            if(sum == target) {
                ans.push_back(curr);   
            }
            return;
        }
        // if
        //recursive case

        if(i == 0 or candidates[i] != candidates[i - 1] or check) {
            if(sum + candidates[i] <= target) {
                sum += candidates[i];
                curr.push_back(candidates[i]);
                check = true;
                generate_combinations(candidates, n, target, ans, curr, i + 1, sum, check);
                sum -= candidates[i];
                curr.pop_back();
                check = false;
            }
            // f(candidates, n, target, and, curr, i + 1, sum);
        }
        generate_combinations(candidates, n, target, ans, curr, i + 1, sum, check);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>curr;
        int i = 0, sum = 0;
        bool check = 0;
        generate_combinations(candidates, candidates.size(), target, ans, curr, i, sum, check);
        return ans;
    }
};