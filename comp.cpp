#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int numOfAps(int arr[], int n){
	int minarr=INT_MAX, maxarr= INT_MIN;

	for(int i=0;i<n;i++){
		minarr= min(minarr,arr[i]);
		maxarr= max(maxarr, arr[i]);
	}

	int dp[n], sum[1001];

	ll ans=n+1;

	for(int diff=(minarr-maxarr);diff<=(maxarr-minarr);diff++){
		memset(sum,0,sizeof sum);

		for(int i=0;i<n;i++){
			dp[i]=1;

			if(arr[i]-diff>=1 && arr[i]-diff<=10000){
				dp[i]+=sum[arr[i]-diff];
			}

			ans+=dp[i]-1;
			sum[arr[i]]+=dp[i];

		}
	}

	return ans;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	cout<<numOfAps(arr, n)<<endl;

	
}