#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long


int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.length();
		int occured[256];
		for(int i=0;i<256;i++){
			occured[i]=-1%mod;
		}
		ll dp[n+1];
		dp[0]=1;
		for(int i=1;i<=n;i++){
			dp[i]=(2L*dp[i-1])%mod;

			if(occured[s[i-1]]!=-1){
				dp[i]=(dp[i]%mod-dp[occured[s[i-1]]]+mod)%mod;
			}

			occured[s[i-1]]=i-1;
		}

		cout<<dp[n]%mod<<endl;
	}
}