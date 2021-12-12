#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define MAX 1000001

void multiply(ll mat[2][2], ll m[2][2]){
	ll fvalue= ((mat[0][0]*m[0][0]+mod)%mod+ (mat[0][1]*m[1][0]+mod)%mod);
	ll svalue= ((mat[0][0]*m[0][1]+mod)%mod+ (mat[0][1]*m[1][1]+mod)%mod);
	ll tvalue= ((mat[1][0]*m[0][0]+mod)%mod+ (mat[1][1]*m[1][0]+mod)%mod);
	ll lvalue= ((mat[1][0]*m[0][1]+mod)%mod+ (mat[1][1]*m[1][1]+mod)%mod);

	mat[0][0]=(fvalue+mod)%mod;
	mat[0][1]=(svalue+mod)%mod;
	mat[1][0]=(tvalue+mod)%mod;
	mat[1][1]=(lvalue+mod)%mod;
}

void power(ll mat[2][2], ll n){

	if(n==0 || n==1){
		return;
	}

	power(mat,n/2);

	multiply(mat,mat);

	if(n%2!=0){
		ll m[2][2]={{1LL,1LL},{1LL,0LL}};
		multiply(mat,m);
	}
}

ll fib(ll n){
	if(n==0){
		return 0;
	}

	ll mat[2][2]= {{1LL,1LL},{1LL,0LL}};

	power(mat,n-1);
	return mat[0][0];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll mfibsum= fib(m+2);
		ll nfibsum= fib(n+1);
		ll ans= (mfibsum-nfibsum)%mod;
        ans= (ans+mod)%mod;
		cout<<ans<<endl;
	}
}