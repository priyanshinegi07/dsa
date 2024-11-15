// TC : O(n! * n)
// SC : O(n + n) for current vector and map
class Solution {
public:
    void generate_permutations(vector<int>&nums, vector<vector<int>> &ans, unordered_map<int, bool> &mp, vector<int>&curr, int n) {
        //base case
        if(curr.size() == n) {
            ans.push_back(curr);
            return;
        }
        //recursive case
        
        for(int i = 0; i < n; i++) {
            //nums[i] is not taken till now in current permutation
            if(mp[nums[i]] == 0) {
                curr.push_back(nums[i]);
                mp[nums[i]] = 1;
                generate_permutations(nums, ans, mp, curr, n);
                // mp.erase(nums[i]);
                mp[nums[i]] = false;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, bool>occurrence;//w can use arr or vector also
        vector<vector<int>>ans;
        vector<int>curr;
        int n = nums.size();
        // cout<<occurrence[nums[0]]<<endl;
        // cout<<occurrence.size()<<endl;
        generate_permutations(nums, ans, occurrence, curr, n);
        return ans;
    }
};

//approach 2
// TC : O(n! * n)
// SC : O(1)
class Solution {
public:
    void generate_permutations(vector<vector<int>>&ans, vector<int>nums, int indx, int n) {
        //base case
        if(indx == n) {
            ans.push_back(nums);
            return;
        }
        //recursive case
        
        for(int i = indx; i < n; i++) {
            swap(nums[indx], nums[i]);//every element comes at current index
            generate_permutations(ans, nums, indx + 1, n);
            swap(nums[indx], nums[i]);
        }
    
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        generate_permutations(ans, nums, 0, nums.size());
        return ans;
    }
};