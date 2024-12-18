//we can keep a counter for third merged arr and when its value reaches k we will get our ans
//TC : O(k)
//SC : O(n)


// TC : O(log(min(n, m)))
// SC : O(1)
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int n = arr1.size(), m = arr2.size();
        if(n > m) return kthElement(k, arr2, arr1);
        int low = max(0, k - m), high = min(n, k);
        while(low <= high) {
            int cut1 = (low + high) >> 1;
            int cut2 = k - cut1;
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];
            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if(l1 > r2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }

        }
        return 1;
    }
};
