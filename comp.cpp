#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll stringmaker(string a, string b, string c, ll*** dp){
    if(c.size()==0){
		return 1;
	}
	if(a.size()==0 && b.size()==0){
		return 0;
	}
	if(dp[a.size()][b.size()][c.size()]!=-1){
		return dp[a.size()][b.size()][c.size()];
	}

	ll ans=0;

	for(int i=0;i<a.size();++i){
		if(a[i]==c[0]){
			ans+=stringmaker(a.substr(i+1),b,c.substr(1),dp);
		}
	}
	for(int i=0;i<b.size();++i){
		if(b[i]==c[0]){
			ans+=stringmaker(a,b.substr(i+1),c.substr(1),dp);
		}
	}

	dp[a.size()][b.size()][c.size()]=ans%mod;
	return ans%mod;

}

int main(){
	int t;
	cin>>t;
	while(t--){
		string a,b,c;
		cin>>a>>b>>c;

		int alen=a.size();
		int blen= b.size();
		int clen= c.size();

		ll ***dp= new ll**[alen+1];
		for(int i=0;i<=alen;i++){
			dp[i]= new ll*[blen+1];
			for(int j=0;j<=blen;j++){
				dp[i][j]= new ll[clen+1];
				for(int k=0;k<=clen;k++){
					dp[i][j][k]=-1;
				}
			}
		}

		ll ans= stringmaker(a,b,c,dp);
		cout<<ans<<endl;
	}
}