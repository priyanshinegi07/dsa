class Solution {
public:
    void f(vector<int>nums, vector<vector<int>>&ans, vector<int>&curr, int i, bool check) {
        //base case
        if(i == nums.size()) {
            ans.push_back(curr);
            return;
        }
        //recursive case

        //choose current element
        if(i == 0 or nums[i] != nums[i - 1] or check) {//if we have not taken prev then we will not take current
            curr.push_back(nums[i]);
            f(nums, ans, curr, i + 1, 1);
            curr.pop_back();
        }     
        f(nums, ans, curr, i + 1, 0);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>curr;
        f(nums, ans, curr, 0, 0);
        return ans;
    }
};