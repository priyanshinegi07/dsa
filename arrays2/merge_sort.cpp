#include<iostream>
using namespace std;
void print(int arr[], int m) {
    for(int i = 0; i < m; i++) {
        cout<<arr[i]<<" ";
    }
}
//tc : O(m+n) sc : O(m+n)
void merge_two_sorted_arr(int a1[], int a2[], int m, int n) {
    int i = 0, j = 0, k = 0;
    int temp[m+n];
    while(i < m and j < n){
        if(a1[i] < a2[j]) {
            temp[k++] = a1[i++];
        }
        else {
            temp[k++] = a2[j++];
        }
        
    }
    while(i < m) {
            temp[k++] = a1[i++];
        }
    while(j < n) {
        temp[k++] = a2[j++];
    }
    for(int i = 0; i < m+n; i++) {
        a1[i] = temp[i];
    }
}
//shifting method 
//handled many cases(equal elements aagye to, j mei greater element reh gya aur i last mei pahuch gya..iske liye if lgaya h, >= lgaya h wrna element choot jayenge kisi ek arr mei(equal element choot jayega)) revise on your own
//TC : O((m+n)×m) m+n for outer loop running and m for worst case inner loop running sc: O(1)
//this is not working for all cases like if we have 0 and negative nos
void m2sa(int a1[], int a2[], int m, int n) {
    int last_pos = m;
    int i = 0, j = 0;
    while(j < n and i < m+n) {
        if(a1[i] >= a2[j]) {
            for(int pos = last_pos; pos > i; pos--) {
                a1[pos] = a1[pos-1];
            }last_pos++;
            a1[i++] = a2[j++];
        }
        // else if(a1[i] == a2[j]) {
        //     i++, j++;
        // }
        else {
            i++;
        }
    
        
    }
    if(a1[i-1] == 0) {
        for(int p = last_pos; p < m+n; p++) {
                a1[p] = a2[j];
        }
    }
    // {1, 2};
    // {1, 1, 1, 8};
    
}
//merge arr which has two parts, both parts are sorted,we can sort by comparing arr1 and arr2 elements and this works like insertion sort, if we use temp arr then we reduce time so we prefer temp arr method
void merge_two_sorted_arr2(int a1[], int m, int n) {
    int i = 0, j = m, k = 0;
    int temp[m+n];
    while(i < m and j < m+n){
        if(a1[i] < a1[j]) {
            temp[k++] = a1[i++];
        }
        else {
            temp[k++] = a1[j++];
        }
        
    }
    while(i < m) {
            temp[k++] = a1[i++];
        }
    while(j < n+m) {
        temp[k++] = a1[j++];
    }
    for(int i = 0; i < m+n; i++) {
        a1[i] = temp[i];
    }
}
int main() {
    int a1[10] = {1,3, 5, 7, 9, 9};
    int a2[] = {2, 4, 6, 8};
    int m = 6, n = 4;
//     int m = 10, n = 6;
// 	int a1[m+n];
// 	for(int i = 0; i < m; i++){
// 		a1[i] = i*2;
// 	}
// 	int a2[n];
// 	for(int i = 0; i < n; i++){
// 		a2[i] = i*2+1;
// 	}
    // merge_two_sorted_arr(a1, a2, m, n);
    // print(a1, m+n);
    int a3[] = {1,2,3,4,3,4,5,6};
    merge_two_sorted_arr2(a3, 4, 4);
    print(a3, 8);
    return 0;
}