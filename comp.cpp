#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll maxBlessing(char a[],char b[],int n,int m,int k,ll*** dp){
	if(k==0){
		return 0;
	}

	if(n==0 || m==0){
		return INT_MIN;
	}

	if(dp[n][m][k]!=-1){
		return dp[n][m][k];
	}

	ll first;
	ll second;
	ll third;

	if(a[0]==b[0]){
		int value= a[0];
		first= value+maxBlessing(a+1,b+1,n-1,m-1,k-1,dp);
		second= maxBlessing(a+1,b,n-1,m,k,dp);
		third= maxBlessing(a,b+1,n,m-1,k,dp);

		ll togive= max(first,max(second,third));
		dp[n][m][k]=togive;
		return togive;

	}
	else{
		second= maxBlessing(a+1,b,n-1,m,k,dp);
		third= maxBlessing(a,b+1,n,m-1,k,dp);

		ll togive= max(second,third);
		dp[n][m][k]=togive;
		return togive;
	}
}



int main(){
	int t;
	cin>>t;
	while(t--){
		char a[1001];
		char b[1001];
		cin>>a;
		cin>>b;
		int k;
		cin>>k;

		int n=strlen(a);
		int m=strlen(b);
		ll*** dp=new ll**[n+1];
		for(int i=0;i<=n;i++){
			dp[i]=new ll*[m+1];
			for(int j=0;j<=m;j++){
				dp[i][j]= new ll[k+1];
				for(int f=0;f<=k;f++){
					dp[i][j][f]=-1;
				}
			}
		}

		ll ans= maxBlessing(a,b,n,m,k,dp);
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				delete [] dp[i][j];
			}
			delete [] dp[i];
		}
		delete [] dp;
		if(ans<-25600){
			cout<<"0"<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}
}