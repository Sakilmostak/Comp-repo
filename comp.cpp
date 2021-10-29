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
			int fare[n][m+1];
			
			for(int i=0;i<n;i++){
				for(int j=1;j<=m;j++){
					cin>>fare[i][j];
				}
			}

			ll dp[n][m+2];
			for(int i=0;i<n;i++){
				dp[i][0]=INT_MAX;
				dp[i][m+1]=INT_MAX;
			}
			for(int i=1;i<=m;i++){
				dp[n-1][i]=fare[n-1][i];
			}

			for(int i=n-2;i>=0;i--){
				for(int j=1;j<=m;j++){
					dp[i][j]=fare[i][j]+min(dp[i+1][j],min(dp[i+1][j-1],dp[i+1][j+1]));
				}
			}

			ll ans=INT_MAX;

			for(int i=1;i<=m;i++){
				ans=min(ans,dp[0][i]);
			}

			cout<<ans<<endl;
		}
}