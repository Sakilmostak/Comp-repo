#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll gcd(ll a, ll b){
	if(b==0){
		return a;
	}

	return gcd(b, a%b);
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		ll ans=arr[0];
		for(int i=1;i<n;i++){
			ans= gcd(ans,arr[i]);
		}

		cout<<ans<<endl;


	}
}