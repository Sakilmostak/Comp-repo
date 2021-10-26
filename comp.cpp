#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

struct items{
	int wt;
	int value;
};

int findMaxValue(items it[],int n, int knapwt, int** dp){
	if(n==0){
		return 0;
	}

	if(dp[n][knapwt]!=-1){
		return dp[n][knapwt];
	}

	int first=0;

	if(knapwt-it[0].wt>=0){
		first= it[0].value + findMaxValue(it+1,n-1,knapwt-it[0].wt,dp);
	}

	int second= findMaxValue(it+1,n-1,knapwt,dp);

	int ans= max(first,second);
	dp[n][knapwt]=ans;
	return ans;	
}

int main(){
	
		int n;
		cin>>n;
		items it[n];
		for(int i=0;i<n;i++){
			cin>>it[i].wt;
		}
		for(int i=0;i<n;i++){
			cin>>it[i].value;
		}

		int knapwt;
		cin>>knapwt;
		int** dp= new int*[n+1];
		for(int i=0;i<=n;i++){
			dp[i]= new int[knapwt+1];
			for(int j=0;j<=knapwt;j++){
				dp[i][j]=-1;
			}
		}

		int ans= findMaxValue(it,n,knapwt,dp);

		for(int i=0;i<=n;i++){
			delete [] dp[i];
		}
		delete [] dp;

		cout<<ans<<endl;
		
}