#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int arr[n+1]={0};
		int start[n+1]={0};
		int end[n+1]={0};
		for(int i=0;i<m;i++){
			int l,r;
			cin>>l>>r;
			start[l]++;
			end[r]++;
		}
        
        arr[1]=start[1];
		for(int i=2;i<=n;i++){
			arr[i]=start[i]-end[i-1]+arr[i-1];
		}

		int dp[10001]={0};

		for(int i=1;i<=n;i++){
			dp[arr[i]]++;
		}

		for(int i=9999;i>0;i--){
			dp[i]+=dp[i+1];
		}

		int q;
		cin>>q;
		while(q--){
			int x;
			cin>>x;
			cout<<dp[x]<<endl;
		}

	}
}