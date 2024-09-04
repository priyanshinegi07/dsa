//brute -> to generate all pairs and check
//TC : O(n^2) sc : O(1)

//optimal
//we use merge sort. before merging we check that if first elemtn of left arr forms a pair with an element of right arr then all the elements to the right of left arr will form a pair and we tarverse the next arr from next element and not starting in each check

//TC : O(2nlogn) SC : O(1)
//logn for dividing and in each divide we are traversing entire arr for merging (n) and entire arr for checking (n)

class Solution {
public:
    void m2sa(vector<int>&arr, int s, int e) {
        int i = s, m = (s+e)/2, j = m+1, k = s;
        int temp[1000000];
        while(i <= m and j <= e) {
            if(arr[i] > arr[j]) {
                temp[k++] = arr[j++];
            }
            else {
                temp[k++] = arr[i++];
            }  
        }
        while(i <= m) {
            temp[k++] = arr[i++];
        }
        while(j <= e) {
            temp[k++] = arr[j++];
        }
        for(int i = s; i <= e; i++) {
            arr[i] = temp[i];
        }
    }
    int cout_pairs(vector<int>&arr, int s, int e, int m) {
        int right = m + 1, cnt = 0;
        for(int i = s; i <= m; i++) {
            while(right <= e and arr[i] > 2*(long long)arr[right]) right++;
            cnt += (right - (m+1));
        }
        return cnt;
    }
    int merge_sort(vector<int>&arr, int s, int e) {
        int cnt = 0;
        //base case
        if(s >= e) return cnt;
        //recursive case
        int m = (s+e)/2;
        cnt += merge_sort(arr, s, m);
        cnt += merge_sort(arr, m+1, e);
        cnt += cout_pairs(arr, s, e, m);
        m2sa(arr, s, e);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return merge_sort(nums, 0, n-1);
    }
};

//this sol gets accepted. the above one was giving tle for large cases
//here we have used vector and not temp arr of large size
class Solution {
public:
    void m2sa(vector<int>&arr, int s, int e) {
        int i = s, m = (s+e)/2, j = m+1, k = s;
        // int temp[1000000];
        vector<int>temp;
        while(i <= m and j <= e) {
            if(arr[i] > arr[j]) {
                temp.push_back(arr[j++]);

            }
            else {
                temp.push_back(arr[i++]);
            }  
        }
        while(i <= m) {
            temp.push_back(arr[i++]);
        }
        while(j <= e) {
            temp.push_back(arr[j++]);
        }
        for(int i = s; i <= e; i++) {
            arr[i] = temp[i-s];
        }
    }
    int cout_pairs(vector<int>&arr, int s, int e, int m) {
        int right = m + 1, cnt = 0;
        for(int i = s; i <= m; i++) {
            while(right <= e and arr[i] > 2*(long long)arr[right]) right++;
            cnt += (right - (m+1));
        }
        return cnt;
    }
    int merge_sort(vector<int>&arr, int s, int e) {
        int cnt = 0;
        //base case
        if(s >= e) return cnt;
        //recursive case
        int m = (s+e)/2;
        cnt += merge_sort(arr, s, m);
        cnt += merge_sort(arr, m+1, e);
        cnt += cout_pairs(arr, s, e, m);
        m2sa(arr, s, e);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return merge_sort(nums, 0, n-1);
    }
};