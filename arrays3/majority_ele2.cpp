//brute force
//check the freq of every element and store in an arr, when size of this arr is 2 then return this arr, we check the count of element if size of ans arr is 0 or either then element if present in ns arr
//TC : O(n^2) SC : O(1)

//better
//use hashmap or freq arr
//TC : O(n) (for freq arr or unordered map), O(nlogn) for ordered map(ordered map insetion takes logn and in worst case we can put all elements in map and there is no majority element)
//SC : O(n)
//we can reduce traversal on map...we check if the freq of curr element in map is having min freq (n/3+1) then we add this in ans arr directly
//therefore we do not traverse again
//if size of ans is 2 then we return and do not do further iterations
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int, int>umap;
        for(int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }
        for(auto num : umap) {
            if(num.second > nums.size()/3) ans.push_back(num.first);
        }
        return ans;
    }
};

//optimal
//TC : O(n) SC :O(1)
//modified moore's voting algo
//we take cnt1, cnt2, ele1, ele2

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int ele1 = INT_MIN, ele2 = INT_MIN, cnt1 = 0, cnt2 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(cnt1 == 0 and nums[i] != ele2) {
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 and nums[i] != ele1) {
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(ele1 == nums[i]) cnt1++;
            else if(ele2 == nums[i]) cnt2++;
            else {
                cnt1--,
                cnt2--;
            }
        }
        // cout<<ele1<<" "<<ele2<<endl;
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == ele1) cnt1++;
            else if(nums[i] == ele2) cnt2++;
            
            // if(ans.size() == 2) return ans;
        }
        if(cnt1 > n/3) ans.push_back(ele1);
        if(cnt2 > n/3) ans.push_back(ele2);
        return ans;
    }
};

