// create seperate arr of size m+n and store ans in this new arr
//TC : O(m+n) SC : O(m+n)
//if something gets continuously divided by 2 for example in a loop then TC for that loop if logbase2n (n is being divided)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k = 0;
        vector<int>ans(nums1.size());
        while(i < m and j < n) {
            if(nums1[i] <= nums2[j]) {
                ans[k++] = nums1[i++];
            }
            else { 
                ans[k++] = nums2[j++];
            }
        }
        while(i < m) {
            ans[k++] = nums1[i++];
        }
        while(j < n) {
            cout<<n<<" ";
            cout<<nums2[j]<<j<<endl;
            ans[k++] = nums2[j];j++;
            
        }
        for(auto i : ans) {
            cout<<i<<" ";
        }
    }
};
//we start iterating from the end of nums1 and place larger element in the end accordingly
//TC : O(m+n) SC : O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        int end_indx = m + n - 1;
        m--, n--;
        while(m >= 0 and n >= 0) {
            if(nums1[m] <= nums2[n]) {
                nums1[end_indx--] = nums2[n--];
            }
            else {
                nums1[end_indx--] = nums1[m--];
            }
            
        }
        cout<<end_indx<<endl;
        while(m >= 0) {
            nums1[end_indx--] = nums1[m--];
        }
        while(n >= 0) {
            nums1[end_indx--] = nums2[n--];
        }
    }
};

//if we do not have to store the ans in nums1 and rather order nums1 and nums2 such that nums1 is smaller than nums2 altogether then we have following three approaches
//1. Brute : take extra arr and put the elements using the above first approach 
//for size equal to nums1 size put the elements in nums1 and put the remaining elements(this will be equal to size of nums2) in nums2 tc is O(m+n) sc is O(m+n)
// 2.optimal 1 : take 2 pointers, first from the ending of nums1 and second from starting of nums2, if the first pinter element is greater then swap first and second pinter elements
// swap the two arrs,  tc is O(min(n, m) + O(n*logn) + O(m*logm)) by sc is constant
// 2. optimal 2 : gap method, gap = len/2 ki ceil value, taken from shell algo, first pointer will start from 0 index of nums1 and second will start from gap distance ahead.right  = left + gap, left will start from 0 for each gap iteration,
// then do swapping if right if greater and check for three condition!!! 
// in end when gap is 1 sort num1 and nums2
// tc O((n+m)*log(n+m))
// sc is contant