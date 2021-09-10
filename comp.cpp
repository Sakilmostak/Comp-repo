#include<bits/stdc++.h>
using namespace std;

long long getMinSum(long long *arr, int n){
    if(n==1){
        return 0;
    }
    int mid=n/2;
    long long ans1= getMinSum(arr,mid);
    long long ans2= getMinSum(arr+mid,n-mid);

    long long total=0;
    
    
    int i=0,j=mid,k=0;
    long long temp[n];
    while(i<mid && j<n){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            total+= arr[i]*(n-j);
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    
    while(i<mid){
        temp[k]=arr[i];
        k++;
        i++;
    }
    
    while(j<n){
        temp[k]=arr[j];
        k++;
        j++;
    }
    
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
    
    return ans1+ans2+total;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
    	cin >> n;

    	long long* arr = new long long[n];

    	for(int i = 0; i < n; ++i)
    	{
        	cin >> arr[i];
    	}

    	cout << getMinSum(arr, n)<<endl;

    	delete arr;
    }
}