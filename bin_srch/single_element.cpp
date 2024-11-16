class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0, e = nums.size() - 2;
        while(s <= e) {
            int m = (s + e) / 2;
            cout<<m<<" ";
            // if(!m) return nums[m];
            // if(nums[m] != nums[m - 1] and nums[m] != nums[m + 1]) return nums[m];
            if((m % 2)) {
                if(nums[m] == nums[m + 1]) // we are in right half
                    e = m - 1;
                else s = m + 1;

            }
            else {
                if(nums[m] == nums[m + 1]) // we are in left half
                    s = m + 1;
                else e = m - 1;

            }
        }
        return nums[s];

    }
};