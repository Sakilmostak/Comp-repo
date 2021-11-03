#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll adjBitReq(int n,int k,int first,ll*** dp){
	if(k<0){
		return 0;
	}
    if(n==1){
		if(k==0){
			return 1;
		}
		else{
			return 0;
		}
    }

	
    
    if(dp[first][n][k]!=-1){
        return dp[first][n][k];
    }
    
  

	if(first==1){
		ll togive= (adjBitReq(n-1,k-1,1,dp)+adjBitReq(n-1,k,0,dp))%mod;
        dp[first][n][k]=togive;
        return togive;
	}
	else if(first==0){
		ll togive=  (adjBitReq(n-1,k,1,dp)+adjBitReq(n-1,k,0,dp))%mod;
        dp[first][n][k]=togive;
        return togive;
	}
}


int main(){
	int t;
	cin>>t;
    ll ans[101+1][101];
        ll*** dp=new ll**[2];
		for(int i=0;i<2;i++){
			dp[i]=new ll*[100+5];
			for(int j=0;j<=100+4;j++){
				dp[i][j]= new ll[100+5];
				for(int f=0;f<=100+4;f++){
					dp[i][j][f]=-1;
				}
			}
		}
    for(ll n=1;n<=100;n++){
        for(ll k=1;k<=100;k++){
        
            ans[n][k]=adjBitReq( n+1,k, 0, dp);
        }
    }
    
	while(t--){
		int n,k;
		cin>>n>>k;

		

		cout<<ans[n][k]<<endl;
	}
}