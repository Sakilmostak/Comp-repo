#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

struct party{
	int cost;
	int fun;
};

int main(){
	
		int n;
		cin>>n;
		party p[n];
		for(int i=0;i<n;i++){
			cin>>p[i].cost;
		}
		for(int i=0;i<n;i++){
			cin>>p[i].fun;
		}

		int money;
		cin>>money;
		
		int dp[n+1][money+1];
		int sum[n+1][money+1];
		for(int i=0;i<=n;i++){
			dp[i][0]=0;
			sum[i][0]=0;
		}

		for(int i=0;i<=money;i++){
			dp[0][i]=0;
			sum[0][i]=0;
		}

		for(int i=1;i<=n;i++){
			for(int j=1;j<=money;j++){
				dp[i][j]=dp[i-1][j];
				sum[i][j]=sum[i-1][j];
				int comp=0;
				if(p[i-1].cost<=j){
					comp=p[i-1].fun + dp[i-1][j-p[i-1].cost];
				}
				if(comp>dp[i][j]){
					dp[i][j]=comp;
					sum[i][j]=p[i-1].cost+ sum[i-1][j-p[i-1].cost];
				}
				else if(comp==dp[i][j]){
					sum[i][j]=min(sum[i-1][j],p[i-1].cost+ sum[i-1][j-p[i-1].cost]);
				}
			}
		}

		cout<<sum[n][money]<<" "<<dp[n][money]<<endl;
		
}