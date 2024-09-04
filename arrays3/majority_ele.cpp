#include<iostream>
using namespace std;
//brute : 2 loops and check the count of every element , if greater than n/2 return the element
//TC : O(n^2) SC : O(1)

//freq arr
//TC : O(2n) SC : O(n)

//O(nlogn) SC : O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // int n = nums.size()/2;
        return nums[nums.size()/2];
    }
};

//optimal approach
//Moore's Voting algo
//TC : O(2n) SC : O(1)
//we assume that first element is majority and increase the cnt from 0 to 1
//if the cnt becomes 0 at any pt then the element choose is not majority till current array because it's cnt gets cancelled so we take next element as majority and continue the same process
//the element we got at last is the majority element if there exists any majority element
//so we iterate over arr and check for it's cnt
//checking is not required if we are sure that there is majority element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = -1, cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(cnt == 0) {
                ele = nums[i];
                cnt++;
            }
            else if(ele == nums[i]) {
                cnt++;
            }
            else {
                cnt--;
            }
        }
        // return ele;
        int cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == ele) cnt2++;
        }
        if(cnt2 > n/2) return ele;
        return -1;
    }
};