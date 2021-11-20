#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll finddiff(string s[], int n, int pos, ll mask, ll** dp){
	if((mask&(mask-1))==0){
		return 0;
	}

	if(pos<0){
		return 10000;
	}
    
    if(dp[pos][mask]!=INT_MAX){
        return dp[pos][mask];
    }

	ll mask1=0;
	ll mask2=0;
    int touches=0;
	for(int i=0;i<n;i++){
		if((mask&(1<<i))!=0){
            touches++;
			if(s[i][pos]=='0'){
				mask1= mask1 | (1<<i);
			}
			if(s[i][pos]=='1'){
				mask2= mask2 | (1<<i);
			}
		}	
	}

	ll first = finddiff(s,n,pos-1,mask1,dp);
	ll second = finddiff(s,n,pos-1,mask2,dp);
	ll third = finddiff(s,n,pos-1,mask,dp);

	ll ans = min(first+second+touches,third);
    dp[pos][mask]=ans;

	return ans;


}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s[n];
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
        

		int strsize= s[0].size();
		ll mask = (1<<n)-1;
        
        ll ** dp= new ll*[strsize];
        for(int i=0;i<strsize;i++){
            dp[i]= new ll[(1<<n)];
            for(int j=0;j<=mask;j++){
                dp[i][j]=INT_MAX;
            }
        }

		ll ans= finddiff(s,n,strsize-1,mask,dp);
		cout<<ans<<endl;
	}
}