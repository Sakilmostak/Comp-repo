#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int main(){
	int t;
	cin>>t;
	while(t--){
		char s1[101];
		char s2[101];
		cin>>s1;
		cin>>s2;
		int m= strlen(s1);
		int n= strlen(s2);

		int** dp= new int*[m+1];
		for(int i=0;i<=m;i++){
			dp[i]= new int[n+1];
		}

		for(int i=0;i<=m;i++){
			dp[i][0]=0;
		}
		for(int i=0;i<=n;i++){
			dp[0][i]=0;
		}

		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(s1[m-i]==s2[n-j]){
					dp[i][j]=1+dp[i-1][j-1];
				}
				else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}

		int ans= dp[m][n];
		for(int i=0;i<=m;i++){
			delete [] dp[i];
		}
		delete [] dp;
		cout<<ans<<endl;
	}
}