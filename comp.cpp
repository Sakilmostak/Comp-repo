#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

struct items{
	int profit;
	int wt;
};

bool comp(items a,items b){
	return a.profit<b.profit;
}


int main(){
	
		int t;
		cin>>t;
		while(t--){
			int n,w;
			cin>>n>>w;
			items item[n];
			for(int i=0;i<n;i++){
				cin>>item[i].profit;
			}

			for(int i=0;i<n;i++){
				cin>>item[i].wt;
			}

			sort(item,item+n,comp);
			
			ll*** dp= new ll**[2];
			for(int i=0;i<2;i++){
				dp[i]=new ll*[n+1];
				for(int j=0;j<=n;j++){
					dp[i][j]= new ll[w+1];
					for(int k=0;k<=w;k++){
						dp[i][j][k]=0;
					}
				}
			}

			int primes[11]= {1,2,3,5,7,11,13,17,19,23,29};

			for(int i=1;i<=n;i++){
				for(int j=1;j<=w;j++){
					dp[0][i][j]=dp[0][i-1][j];

					if(item[i-1].wt<=j){
						dp[0][i][j]=max(dp[0][i][j],dp[0][i-1][j-item[i-1].wt]+item[i-1].profit);
					}
				}
			}

			for(int prime= 1;prime<=10;prime++){
				int p=prime%2;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=w;j++){
						dp[p][i][j]=dp[p][i-1][j];
						if(item[i-1].wt<=j){
							dp[p][i][j]= max(dp[p][i][j],max(dp[p][i-1][j-item[i-1].wt]+item[i-1].profit,dp[p^1][i-1][j-item[i-1].wt]+ (item[i-1].profit*primes[prime])));
						}
					}
				}
			}

			cout<<dp[0][n][w]<<endl;


		}
}