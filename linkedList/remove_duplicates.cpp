//brute : insert all elements in set and then insert back the elements from set to the original array
//TC : O(NlogN + N) SC : O(N) insertion in set takes logn, elements in set are sorted

//optimal : two pointer
//when we get the first elements we have to skip all the duplicate elements after that
//one pointer will traverse the arr and second will skip all the duplicate elements
//TC : O(n) SC : O(1)
//the first code is my implementation
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int n = nums.size(), k = 1, j = 1;
        // for(int i = 0; i < n; i++) {
            
        //     while(j < n && nums[j] == nums[i]) j++;
        //     if(j != n) {
        //         k++;
        //         nums[i + 1] = nums[j];
        //     }
        // }
        // return k;
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] != nums[i]) {
                nums[i + 1] = nums[j];
                i++;
            }
        }
        return i + 1;
        
    }
};