//for every element run and inner loop and if same element if found icrement freq
//TC :O(n^2) SC : O(1)
//aproach1 sort and then traverse the arr duplicate elements will come together
//tc : O(nlogn + n) sc O(1)


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1]) return nums[i];
        }
        return -1;
    }

};

//approach 2 : create freq arr/hashing
//return element with more than one frequency
//tc : O(n) sc : O(n)

//approach 3 : slow and fast pointer of linked list

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
        slow = nums[slow];
        fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
        }
        return slow;
    
    }
    
};