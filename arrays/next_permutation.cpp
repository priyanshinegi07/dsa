//approach 1 : generate all sorted permutations O(n! * n)
//then do lin srch and then find next index permutation
//approach 2 : stl next_permutation(v.begin(), v.end())
//approach 3:
//we match longest subarr
//we find the first element which is smaller than right part, then swap this ele with smallest element of right part
//the we sort the right part
//TC : O(3n) if we use reverse fun otherwise if we use sort then nlogn SC : O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int right_min, left_min;
        int i = n - 1;
        for(; i > 0; i--) {
            if(nums[i - 1] < nums[i]) {
                left_min = i - 1;
                // cout<<left_min<<endl;
                break;
            }
            // else if(nums[i - 1] > nums[i]) 
            // right_min = min(nums[right_min], nums[i]);
        }
        cout<<left_min<<endl;
        if(i == 0) {
            sort(nums.begin(), nums.end()); 
            return;
        }
        for(int i = n - 1; i > left_min; i--) {
            if(nums[i] > nums[left_min]) {
                right_min = i;
                break;
            }
        }
        swap(nums[left_min], nums[right_min]);
        sort(nums.begin() + left_min + 1, nums.end() );
        cout<<i<<endl;
        

       
    }
};