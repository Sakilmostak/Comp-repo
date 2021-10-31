#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int shortSub(char a[], char b[],int n, int m, int** dp){
	if(n==0 && m==0){
		return 0;
	}

	if(dp[n][m]!=-1){
		return dp[n][m];
	}

	if(n==0){
		int third= 1+shortSub(a,b+1,0,m-1,dp);
		dp[n][m]=third;
		return third;
	}
	if(m==0){
		int fourth= 1+shortSub(a+1,b,n-1,m,dp);
		dp[n][m]=fourth;
		return fourth;
	}

	if(a[0]==b[0]){
		int fifth= 1+shortSub(a+1,b+1,n-1,m-1,dp);
		dp[n][m]=fifth;
		return fifth;
	}
	int first= 1+shortSub(a+1,b,n-1,m,dp);
	int second= 1+shortSub(a,b+1,n,m-1,dp);

	dp[n][m]= min(first,second);
	return min(first,second);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		char a[501];
		char b[501];
		cin>>a;
		cin>>b;
		int n=strlen(a);
		int m=strlen(b);
		int** dp= new int*[n+1];
		for(int i=0;i<=n;i++){
			dp[i]=new int[m+1];
			for(int j=0;j<=m;j++){
				dp[i][j]=-1;
			}
		}

		int ans= shortSub(a,b,n,m,dp);
		for(int i=0;i<=n;i++){
			delete [] dp[i];
		}
		delete [] dp;
		cout<<ans<<endl;
	}
}