//approach 1 : three loops O(n^3)
//approach 2 : two loops csum arr for innermost loop O(n^2)
//approach 3 : one loop kadanes algo O(n)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx =INT_MIN;
        int csum = 0;
        for(int i = 0; i < nums.size(); i++) {
            csum += nums[i];
            mx = max(mx, csum);
            csum = max(csum, 0);
        }
        return mx;
    }
};