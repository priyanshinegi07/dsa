// TC : O(m + n)
// SC : O(m + n)
class Solution {
public:
    vector<int> merge_arr(vector<int>&nums1, vector<int>&nums2, int m, int n) {
        vector<int>temp(m + n);
        int i = 0, j = 0, k = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                temp[k++] = nums1[i++];
            }
            else {
                temp[k++] = nums2[j++];
            }
        }
        while(i < m) {
            temp[k++] = nums1[i++];
        }
        while(j < n) {
            temp[k++] = nums2[j++];
        }
        return temp;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        // vector<int>temp(m+n);
        vector<int>temp = merge_arr(nums1, nums2, m, n);
        if((m + n) % 2) {//there is 1 median
            return temp[(m + n) / 2];
        }
        cout<<temp.size()<<endl;

        for(int i = 0; i < temp.size(); i++) cout<<temp[i]<<" ";
        cout<<temp[(m + n) / 2]<<" "<<temp[(m + n - 1) / 2]<<endl;//or (m+n)/2 - 1
        return (temp[(m + n) / 2] + temp[(m + n - 1) / 2])/2.0;
        // return 0;

    }
};

//SC : O(1) tc is same
class Solution {
public:
    void merge_arr(vector<int>&nums1, vector<int>&nums2, int m, int n, int &ele1, int &ele2) {
        int i = 0, j = 0, k = 0;// k is the current index of arr 3(imaginary) we are looking for
        int indx1 = ele1, indx2 = ele2;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                if(k == indx1) ele1 = nums1[i];
                if(k == indx2) ele2 = nums1[i];
                k++, i++;
                

            }
            else {
                if(k == indx1) ele1 = nums2[j];
                if(k == indx2) ele2 = nums2[j];
                k++, j++;
            }
            
        }
        while(i < m) {
            if(k == indx1) ele1 = nums1[i];
            if(k == indx2) ele2 = nums1[i];
            k++, i++;
        }
        while(j < n) {
            if(k == indx1) ele1 = nums2[j];
            if(k == indx2) ele2 = nums2[j];
            k++, j++;
        }
        // return temp;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int ele1, ele2;
        ele1 = (m + n)/2;
        ele2 = (m + n)/2 - 1;
        cout<<ele1<<" "<<ele2<<endl;
        merge_arr(nums1, nums2, m, n, ele1, ele2);
        cout<<ele1<<" "<<ele2<<endl;
        if((m + n) % 2) return ele1;
        return (ele1 + ele2)/2.0;
        // return 0;

    }
};

// TC : O(log(min(n1, n2)))
// SC : O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n1;
        int left = (n1 + n2 + 1) / 2;
        int n = n1 + n2;
        while(low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            if(l1 <= r2 && l2 <= r1) {
                if(n % 2 == 1) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2))/2.0;
            }
            else if(l1 >= r2) high = mid1 - 1;
            else low = mid1 + 1;
            
        }
        return 0;

    }
};