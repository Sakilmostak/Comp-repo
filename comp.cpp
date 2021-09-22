#include<bits/stdc++.h>

using namespace std;

void subsetSum(int arr[], int n, int sum, int &count){
    if(n==0){
        if(sum==0){
            count++;
        }
        return;
    }

    subsetSum(arr+1, n-1, sum, count);
    subsetSum(arr+1,n-1, sum-arr[0], count);

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        int count=0;

        subsetSum(arr, n, k, count);
        
        cout<<count<<endl;
    }
}