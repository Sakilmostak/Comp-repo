#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll euclidGcd(int a, int b){
	if(b==0){
		return a;
	}

	return euclidGcd(b, a%b);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll x,y;
		cin>>x>>y;

		ll ans;

		if(x>y){
			ans=euclidGcd(x,y);
		}
		else{
			ans=euclidGcd(y,x);
		}

		cout<<ans<<endl;
	}
}