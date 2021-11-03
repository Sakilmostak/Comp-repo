#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll adjBitReq(int n,int k,int first,ll*** dp){
	if(n==1){
		if(k==0){
			return 1;
		}
		if(k>0){
			return 0;
		}
	}

	if(k<0){
		return 0;
	}

	if(first==1){
		return adjBitReq(n-1,k-1,1,dp)+adjBitReq(n-1,k,0,dp);
	}
	else if(first==0){
		return adjBitReq(n-1,k,1,dp)+adjBitReq(n-1,k,0,dp);
	}
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;

		ll*** dp=new ll**[2];
		for(int i=0;i<2;i++){
			dp[i]=new ll*[n+1];
			for(int j=0;j<=n;j++){
				dp[i][j]= new ll[k+1];
				for(int f=0;f<=k;f++){
					dp[i][j][f]=-1;
				}
			}
		}

		ll ans= adjBitReq(n+1,k,0,dp);
		for(int i=0;i<2;i++){
			for(int j=0;j<=n;j++){
				delete [] dp[i][j];
			}
			delete [] dp[i];
		}
		cout<<ans<<endl;
	}
}