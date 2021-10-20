#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	ll dp[n];
	dp[0]=arr[0];
	dp[1]=arr[1];
	ll maxbonus= arr[0];
	for(int i=2;i<n;i++){
		maxbonus=max(maxbonus,dp[i-2]);
		dp[i]=maxbonus+ arr[i];
	}

	ll ans=0;

	for(int i=0;i<n;i++){
		ans=max(ans,dp[i]);
	}

	cout<<ans<<endl;

	return 0;
}