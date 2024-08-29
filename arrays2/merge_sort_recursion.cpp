#include<iostream>
using namespace std;
void print(int arr[], int n) {
    for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
    cout<<endl;
}
void m2sa(int a1[], int s, int e) {//s and e are indices
    int m = (s+e)/2;
    int i = s, j = m+1, k = s;
    int temp[1000000];
    while(i <= m and j <= e){//<= because m is index
        if(a1[i] < a1[j]) {
            temp[k++] = a1[i++];
        }
        else {
            temp[k++] = a1[j++];
        }
        
    }
    while(i <= m) {
            temp[k++] = a1[i++];
        }
    while(j <= e) {
        temp[k++] = a1[j++];
    }
    for(int i = s; i <= e; i++) {
        a1[i] = temp[i];
    }
}
void merge_sort(int arr[], int s, int e) {
    //base case
    if(s >= e) return;
    //recursive case
    int m = (s+e)/2;
    merge_sort(arr, s, m);
    merge_sort(arr, m+1, e);
    m2sa(arr, s, e);
}

int main() {
    int arr[] = {7, 5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr, 0, n-1);
    print(arr, n);
    return 0;
}