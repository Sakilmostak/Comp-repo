#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int totalspecialperm(int n){
	int dp[1<<n];
	int mask=(1<<n)-1;
	for(int i=0;i<=mask;i++){
		dp[i]=0;
	}
	dp[0]=1;
	for(int i=0;i<mask;i++){
		for(int j=0;j<n;j++){
			if((1<<j & i)==0){
				bool flag=false;
				for(int k=0;k<n;k++){
					if(((j+1)&(k+1))==j+1 && ((1<<k)&i)){
						flag=true;
						break;
					}
				}
				if(flag==false){
					dp[1<<j | i]+=dp[i];
				}
			}
		}
	}

	return dp[mask];
}


int main(){
	int n;
	cin>>n;
	int ans= totalspecialperm(n);
	cout<<ans<<endl;
}