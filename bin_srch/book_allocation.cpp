// https://leetcode.com/problems/split-array-largest-sum/description/
//above leetcode ques is same as the book allocation problem
// TC : O(n) * O(log(sum - max + 1))
bool can_read_pages(int max_pages, vector<int>&A, int B) {
    int curr_pages = 0;
    int stud = 1, i = 0;
    while(i < A.size()) {
        if (A[i] > max_pages) return false;
        if(curr_pages + A[i] <= max_pages) {
            curr_pages += A[i];
            // i++;
            
        }
        else {
            stud++;// next student will read
            curr_pages = A[i];
            if (stud > B) return false;
        }
        i++;
    }
    // cout<<stud<<" "<<max_pages<<endl;
    return stud <= B;
}
int Solution::books(vector<int> &A, int B) {
    if(B > A.size()) return -1;
    int s = *max_element(A.begin(), A.end());
    int e = 0;
    for(int i = 0; i < A.size(); i++) {
        e += A[i];
        // cout<<A[i]<<" ";
    } 
    // cout<<"e"<<e<<endl;
    int ans = -1;
    while(s <= e) {
        int mid = (s + e) / 2;
        if(can_read_pages(mid, A, B)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}
