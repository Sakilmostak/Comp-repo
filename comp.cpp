#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int grundyOpt(ll n){
	ll i=1LL;
	ll j,k,l,m,res=0LL;
	if(n==i){
		return 1;
	}
	while(true){

		m=i+res;
		if(n<=m){
			return 1;
		}
		//cout<<m+1<<" ";
		j=(2*i)+m;
		if(n<=j){
			return 2;
		}
		//cout<<j+1<<" ";
		k=(2*i)+j;
		if(n<=k){
			return 3;
		}
		//cout<<k+1<<" ";
		l=(6*i)+k;
		if(n<=l){
			return 0;
		}
		//cout<<l+1<<" ";
		
		res=l;
		i=12*i;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
        
		//cout<<grundy(n)<<endl;
		cout<<grundyOpt(n)<<endl;
       
	}
}
