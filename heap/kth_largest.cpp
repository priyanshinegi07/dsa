//we created a heap for all the elements, then max element is at the top, so if we want third(k) largest element, then we removed 2(k-1) elements from the top
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int s = nums.size() - k;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        k--;
        while(k--) {
            pq.pop();
        }
        return pq.top();
    }
};

//third largest will the smallest among top three elements so we create a min heap , last mei we will have heap of top k elements among which the top element will be min
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        int i;
        for(i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        while(i < nums.size()){
            int curr = nums[i];
            if(pq.top() < curr){
                pq.pop();
                pq.push(curr);
            }i++;
        }
        return pq.top();
    }
};