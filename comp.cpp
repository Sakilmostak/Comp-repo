#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll findMaxStock(int arr[],int n,int k,int trans,ll*** dp){
	if(n==0){
		return 0L;
	}
	ll first=INT_MIN;
	ll second=INT_MIN;
	ll third=INT_MIN;

	if(dp[trans][n][k]!=INT_MIN){
		return dp[trans][n][k];
	}

	first= findMaxStock(arr+1,n-1,k,trans,dp);
	if(trans==1){
		second=findMaxStock(arr+1,n-1,k-1,0,dp)+arr[0];
	}
	if(trans==0 && k>0){
		third=findMaxStock(arr+1,n-1,k,1,dp)-arr[0];
	}

	ll maxvalue= max(first,max(second,third));
	dp[trans][n][k]=maxvalue;

	return maxvalue;

}


int main(){
	int t;
	cin>>t;
	while(t--){
		int k,n;
		cin>>k;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		ll*** dp= new ll**[2];
		for(int i=0;i<2;i++){
			dp[i]= new ll*[n+1];
			for(int j=0;j<=n;j++){
				dp[i][j]= new ll[k+1];
				for(int f=0;f<=k;f++){
					dp[i][j][f]=INT_MIN;
				}
			}
		}

		ll ans= findMaxStock(arr,n,k,0,dp);
		cout<<ans<<endl;
	}
}