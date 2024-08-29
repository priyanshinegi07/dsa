//Approach 1 : we check every element of arr that if the new element if less than this curr element then cnt++
//take two loops...i = 0 to n-1 and j = i+1 to n
//if(arr[i] > arr[j]) cnt++
//essentially we are generating all pairs and cnt the number of desired pairs
//TC : O(n^2) SC : O(1)

//Approach 2 : merge sort modified
//we change the m2sa function a bit
//the place where we are comparing arr[i] < arr[j], before this we compare that if arr[i] > arr[j] then cnt++
//ex - we have 5,3 then cnt++
//after this these parts will be sorted and double double cnt will not be there
//TC : O(nlogn) SC : O(1)
#include<iostream>
using namespace std;
void m2sa(int arr[], int s, int e, long long &cnt) {
    int i = s, m = (s+e)/2, j = m+1, k = s;
    int temp[1000000];
    while(i <= m and j <= e) {
        if(arr[i] > arr[j]) {
            cnt += m - i + 1;
            // cout<<"cnt"<<cnt<<" "<<arr[i]<<" "<<arr[j]<<endl;
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
void merge_sort(int arr[], int s, int e, long long &cnt) {
    //base case
    if(s >= e) return;
    //recursive case
    int m = (s+e)/2;
    merge_sort(arr, s, m, cnt);
    merge_sort(arr, m+1, e, cnt);
    m2sa(arr, s, e, cnt);
}
int main() {
    int arr[] = {52244275, 123047899, 493394237, 922363607, 378906890, 188674257, 222477309, 902683641, 860884025, 339100162};
    int n = sizeof(arr)/sizeof(arr[0]);
    long long cnt = 0;
    merge_sort(arr, 0, n-1, cnt);
    cout<<cnt;
    return 0;
}

