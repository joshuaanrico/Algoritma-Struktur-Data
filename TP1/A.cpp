#include<iostream>
using namespace std;

void penjumlahanSubset(int arr[], int l, int r, int sum){
    if(l>r){
        cout<<sum<<" ";
        return;
    }
    penjumlahanSubset(arr, l+1, r, sum + arr[l]);
    penjumlahanSubset(arr, l+1, r, sum);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    penjumlahanSubset(arr, 0, n-1, 0);
    return 0;
}
