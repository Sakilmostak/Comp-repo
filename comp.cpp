#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int arr[n+1][m+1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>arr[i][j];
			}
		}

		int dp[n+1][m+1];
		for(int i=1;i<=m;i++){
			dp[1][i]=1;
		}

		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(arr[i-1][j]<arr[i][j]){
					dp[i][j]=dp[i-1][j];
				}
				else{
					dp[i][j]=i;
				}
			}
		}

		int ans[n+1];

		for(int i=1;i<=n;i++){
			ans[i]=dp[i][1];
			for(int j=2;j<=m;j++){
				ans[i]=min(ans[i],dp[i][j]);
			}
		}

		int k;
		cin>>k;
		while(k--){
			int l,r;
			cin>>l>>r;
			if(ans[r]<=l){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
		}



	}
}