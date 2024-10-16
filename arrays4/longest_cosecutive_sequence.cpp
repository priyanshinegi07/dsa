//brute : check for every element the longest sequence it can form
//TC : O(n^2) SC : O(1)

//better 
//sort the arr and check the largest sequence that can be formed 
//after each element update the longest = max(longest, curr_length)
//skip the element if it equal to previous
//increase curr_len if the curr_ele + 1 == to prev
//if the curr_ele is not equal to prev make curr_len = 1
//TC : O(nlogn + n) SC : O(1)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
                        //we don't have any seq 
        if(nums.size() == 0) return 0;
        int longest = 1, curr_len = 0, last_smallest = INT_MIN;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(nums[i] - 1 == last_smallest) {
                curr_len += 1;
                last_smallest = nums[i];
            }
            else if(nums[i] != last_smallest) {
                curr_len = 1;
                last_smallest = nums[i];
            }
            longest = max(longest, curr_len);
        }
        return longest;
    }
};

//optimal
//we insert all elements in set
//for every element we check if its previous is present
//if the previous is present then this element lies in mid of seq and we do not check seq from here
//if we get an element which has no prev then this is starting and we cnt the seq length from here
//then we update the longest seq var
//TC : O(3n) for unordered set best and avg case in worst insertion for single element take logn SC : O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int longest = 1;
        unordered_set<int>s;
        int n = nums.size();
        for(int i = 0; i <n; i++) {
            s.insert(nums[i]);
        }
        for(auto element  : s) {
            //this is starting element
            if(s.find(element - 1) == s.end()) {
                int cnt = 1;
                int x = element;
                while(s.find(x+1) != s.end()) {
                    cnt++;
                    x += 1;
                }
                longest = max(longest, cnt);
            }
        } 
        return longest;
    }
};