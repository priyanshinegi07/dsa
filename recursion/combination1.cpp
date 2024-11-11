//TC : O(2^t * k) if we cannot choose one element multiple times then we have only two options(pick/not pick) for a single element so tc is 2^n * k where k is the avg size of current combination, t is the avg no of options for a single element coz we can take one element multiple times, Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.
// SC : O(k * x) where x is no of combinations
class Solution {
public:
    // int n;
    bool check_sum(vector<int>&curr, int n, int target) {
        int sum = 0;
        for(auto i : curr) {
            sum += i;
        }
        if(sum == target) return true;
        // if(sum < target) {
        //     while(sum >= target) {
                
        //     }
        // }
        return false;
    }
    void f(vector<int>&candidates, int n, int &target, vector<int>&curr, int &sum, int i, vector<vector<int>>&ans) {
        //base case
        // cout<<(i)<<endl;
        if(i == n) {
            // cout<<i<<" "<<n<<endl;
            // if(check_sum(curr, curr.size(), target))
            if(sum == target)
                ans.push_back(curr);
            return;
        }
        // else if(sum == target) {
        //     ans.push_back(curr);
        //     return;
        // }
        // cout<<"hello"<<endl;

        //recursive case
        // cout<<sum<<" ";
        // if(sum + candidates[i] > target) return;
        if((sum + candidates[i]) <= target) {

            curr.push_back(candidates[i]);
            sum += candidates[i];
            
            f(candidates, n, target, curr, sum, i, ans);
            sum -= candidates[i];
            curr.pop_back();
        }
        // else if(sum + arr[i] == target) {
        //     curr.push_back(arr[i]);
        //     f(candidates, target, curr, sum, i + 1, ans);
        //     curr.pop_back();
        // }
        f(candidates, n, target, curr, sum, i + 1, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int sum = 0, i = 0;
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>curr;
        // cout<<"n"<<n<<endl;
        f(candidates, n, target, curr, sum, i, ans);
        return ans;
    }
};