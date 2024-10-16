//brute : generate all quads and check
//TC : O(n^4) SC : O(1)

//better : remove innermost loop
//fix i and j and move k, check if target - ([nums[i]+nums[j] + num[k]]) is preset(use hasmap or set) if present then we get a qaud also push this element so that in future also we can check 
//TC : O(n^3logm) SC : O(2*quads + n) n for hashmap that can store atmax n elements 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        set<vector<int>>ans;
        int n = nums.size();
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                unordered_map<long long, int>umap;
                for(int k = j + 1; k < n; k++) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    if(umap.find(fourth) != umap.end()) {
                        vector<int>temp = {nums[i], nums[j], nums[k], int(fourth)};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                    umap[nums[k]] = 1;

                }
            }
        }
        vector<vector<int>>v(ans.begin(), ans.end());
        return v;
    }
};

//optimal 
// we remove set to store unique elements and hashmap to look for required elements
//using two pointer appraoch
//TC : O(n^2 * n) SC : O(1)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n - 3; i++) {
            //skipping ith element which is duplicate
            if(i > 0 and nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < n - 2; j++) {
                //skipping the jth element which is not first element after j coz we'll consider first element
                if(j != i + 1 and nums[j] == nums[j-1]) continue;
                long long l = j + 1, r = n-1;
                while(l < r) {
                    long long sum = nums[i] + nums[l];
                    sum += nums[j];
                    sum += nums[r];
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++, r--;
                        while(l < r and nums[l] == nums[l-1]) {
                            l++;
                            continue;
                        }
                        while(l < r and nums[r] == nums[r+1]) {
                            r--;
                            continue;
                        }
                    }
                    else if(sum < target) l++;
                    else r--;
                }
            }
        }
        
        return ans;
    }
};

// another implementation of above approach done by me
// TC : O(n^2*n) SC : O(n)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> s;
        for(long long i = 0; i < n - 3; i++) {
            for(long long j = i + 1; j < n - 2; j++) {
                long long l = j + 1, r = n-1;
                while(l < r) {
                    long long sum = (long long)nums[i] + (long long)nums[l] + (long long)nums[j] + (long long)nums[r];
                    if(sum == target) {
                        s.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++, r--;
                    }
                    else if(sum < target) l++;
                    else r--;
                }
            }
        }
        vector<vector<int>>ans;
        for(auto item : s) {
            ans.push_back(item);
        }
        return ans;
    }
};