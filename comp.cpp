#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int gcd(int n1,int  n2){
while(n1 != n2) {
    if(n1 > n2)
      n1 -= n2;
    else
      n2 -= n1;
  }
    
    return n1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		ll dp[n][101]={0};
		dp[0][arr[0]]=1;
		for(int i=1;i<n;i++){
            dp[i][arr[i]]=1;
			for(int j=0;j<i;j++){
				if(arr[j]<arr[i]){
					for(int k=1;k<=100;k++){
						int newgcd= gcd(arr[i],k);
						dp[i][newgcd]=(dp[i][newgcd]+dp[j][k])%mod;
						
						
					}
				}
			}
		}

		ll tsum=0;

		for(int i=0;i<n;i++){
			tsum=(tsum+dp[i][1])%mod;
		}

		cout<<tsum<<endl;

	}
}