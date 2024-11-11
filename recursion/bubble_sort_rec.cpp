#include<iostream>
using namespace std;
void print(int arr[], int n, int i) {
    //base case
    if(i == n) return;
    //recursive case
    cout<<arr[i]<<" ";
    print(arr, n, i + 1);
}                         //initialization
void bsp(int arr[], int n, int i) {
    // cout<<sizeof(arr)<<" "<<sizeof(arr[0])<<" "<<n<<endl;
    //base case
    if(i == n - 1) return;//condition check
    // for(int i = 0; i < n - 1; i++) {
        //this loop will place the current element at it's position
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) 
                swap(arr[j], arr[j + 1]);
        }
    // }
    //going to next iteration
    //recursive case
    bsp(arr, n, i + 1);//increment/updation

}
void bsf (int arr[], int n, int i, int j) {
    //base case
    if(i == n - 1) return;
    if(j == n-i-1) bsf(arr, n, i+1, 0);
    //recursive case
    else {
        if(arr[j] > arr[j+1])
            swap(arr[j], arr[j+1]);
        bsf(arr, n, i, j + 1);
    }
    
}
int main() {
    int arr[] = {4, 13, 2, 1, -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    bsf(arr, n, 0, 0);
    print(arr, n, 0);
    return 0;
}