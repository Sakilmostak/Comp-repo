#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll totalBrack(bool arr[],int op, int cl, int n,ll** dp){
	if(op>n || cl>n){
		return 0L;
	}

	if(op==n && cl==n){
		return 1L;
	}

	if(dp[op][cl]!=-1){
		return dp[op][cl];
	}

	if(op==cl || arr[op+cl+1]==true){
		ll first= totalBrack(arr,op+1,cl,n,dp)%mod;
		dp[op][cl]=first;
		return first;
	}

	if(op==n){
		ll second= totalBrack(arr,op,cl+1,n,dp)%mod;
		dp[op][cl]=second;
		return second;
	}
	else{
		ll third=totalBrack(arr,op+1,cl,n,dp)%mod;
		ll fourth= totalBrack(arr,op,cl+1,n,dp)%mod;
		dp[op][cl]=(third+fourth)%mod;
		return (third+fourth)%mod;
	}


}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		bool arr[(2*n)+1]={false};
		for(int i=0;i<k;i++){
			int x;
			cin>>x;
			arr[x]=true;
		}

		ll** dp= new ll*[n+1];
		for(int i=0;i<=n;i++){
			dp[i]=new ll[n+1];
			for(int j=0;j<=n;j++){
				dp[i][j]=-1;
			}
		}

		ll ans= totalBrack(arr,0,0,n,dp);
		cout<<ans<<endl;
		
	}
}