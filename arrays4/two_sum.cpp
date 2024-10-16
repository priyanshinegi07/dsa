#include<iostream>
using namespace std;
//brute : generate all pairs and check
//i = 0 to n-1, j = i+1 to n
//TC : O(n^2) SC : O(1)

//better
//we reduct TC from n^2 to n so we have to iterate once
//we stand at every element and check whether its partner (which could sum up to target) is present
//if yes we return the index
//TC : O(n)(for umap and n^2 in worst case) , O(nlogn) in map SC : O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>umap;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            // umap[target - nums[i]];
            if(umap.count(target - nums[i])) {
                return {i, umap[target - nums[i]]};
            }
            else {
                umap[nums[i]] = i;
            }
        }
        return {};
    }
};

//optimal ---> if we have to return yes or no that whether two elements sum up to target or not then this approach is preferred although i hav written the code for --> return the indices of two elements which sum to target
//two pinter approach(first we sort the arr)
//if we get two such elements then we again search for their index by traversing the arr
// TC : O(nlogn) SC : O(1) if we have to return yes/no and O(n) if we have to return indices coz we create a copy to check the indices

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>nums2 = nums;
        sort(nums.begin(), nums.end());
        int s = 0, e = nums.size()-1, n = nums.size();
        bool flag = false;
        while(s < e) {
            if(nums[s] + nums[e] == target) {
                flag = true;
                break;
            }
            else if(nums[s] + nums[e] < target) s++;
            else e--;
        }
        vector<int>ans;
        if(flag) {
            if(nums2[0] == nums[s] or nums2[0] == nums[e]) ans.push_back(0);
            for(int i = 1; i < n; i++) {
                // if(nums[i]==nums[i-1]) continue;
                if(nums2[i] == nums[s] or nums2[i] == nums[e]) ans.push_back(i);
                if(ans.size() == 2) return ans;
                // if(nums2[i] == nums[e]) ans.push_back(i);
                // if(ans.size() == 2) return ans;
            }
        }
        return {};
    }
};
