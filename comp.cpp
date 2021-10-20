#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int main(){
	int t;
	cin>>t;
	while(t--){
		int r,c;
		cin>>r>>c;
		int maze[r][c];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin>>maze[i][j];
			}
		}

		int dp[r][c];
		dp[r-1][c-1]=1;
		//dp[r-2][c-1]=1;
		//dp[r-1][c-2]=1;
		for(int i=r-2;i>=0;i--){
			dp[i][c-1]=dp[i+1][c-1]-maze[i][c-1];
			if(dp[i][c-1]<=0){
				dp[i][c-1]=1;
			}
		}
		for(int j=c-2;j>=0;j--){
			dp[r-1][j]=dp[r-1][j+1]-maze[r-1][j];
			if(dp[r-1][j]<=0){
				dp[r-1][j]=1;
			}
		}

		for(int i=r-2;i>=0;i--){
			for(int j=c-2;j>=0;j--){
				dp[i][j]=min(dp[i+1][j],dp[i][j+1])-maze[i][j];
				if(dp[i][j]<=0){
					dp[i][j]=1;
				}
			}
		}

		cout<<dp[0][0]<<endl;
	}
}