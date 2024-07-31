//TC : O(n) SC : O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = -1;
        for(int indx = 0; indx < nums.size(); indx++){
            if(nums[indx] == 0) {
                swap(nums[++i], nums[indx]);
            }
        }
        int j = i;
        for(int indx = 0; indx < nums.size(); indx++){
            if(nums[indx] == 1) {
                swap(nums[++j], nums[indx]);
            }
        }
 
    }
};
//three pointers, one to traverse, one for zero's pos and one for two's pos
//TC : O(n) SC : O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int n = nums.size();
        int z = 0, i = 0, t = nums.size()-1;
        while(t >= i){
            if(nums[i] == 0){
                swap(nums[z++], nums[i++]);
            }else if(nums[i] == 1){
                    i++;
            }else if(nums[i] == 2){
                swap(nums[i], nums[t--]);
            }
        }
    }
};