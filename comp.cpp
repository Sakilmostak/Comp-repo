#include<bits/stdc++.h> 
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
#define test int t;cin>>t;while(t--)
#define limit 100000
#define setBit(x) __builtin_popcount(x)
 
using namespace std; 
 
ll euclidGcd(ll a, ll b){
	if(b==0){
		return a;
	}
 
	return euclidGcd(b, a%b);
}
 
 
// ll modExp(ll a, ll b, ll md){
//     ll ans = 1;
//     while (b)
//     {
//         if (b & 1)
//         {
//             ans = (__int128)ans * a % md;
//         }
//         b >>= 1;
//         a = (__int128)a * a % md;
//     }
//     return ans;
// }
 
ll modExp(ll a, ll b, ll c){
	if(a==0){
		return 0LL;
	}
	if(b==0){
		return 1LL;
	}
	
	if(b%2==1){
	    ll cur= modExp(a,b/2,c);
	    ll ans= (cur*cur)%c;
	    ans= (ans*a)%c;
		ans= (ans+c)%c;
	    
	    return ans;
	}
	else{
	    ll cur= modExp(a,b/2,c);
	    ll ans= (cur*cur)%c;
		ans=(ans+c)%c;
	    
	    return ans;
	}
 
	
}
 
 
ll factorial(ll n){
	ll ans=1LL;
	for(ll i=2LL;i<=n;i++){
		ans= (ans*i)%mod;
	}
	return ans;
}
 
ll ncr(ll n, ll r){
	ll c1= factorial(n);
	ll c2= factorial(r);
	ll c3= factorial(n-r);
	ll cur= (c2*c3)%mod;
 
	ll ans= (c1*modExp(cur,mod-2,mod))%mod;
 
	return ans;
}
 
 
void makeSieve(int n, vector<bool>& sieve){
    if(n<=1) return;
 
	sieve[0]=0;
	sieve[1]=0;
 
	for(int i=2;i*i<=n;i++){
		if(sieve[i]){
			for(int j=i*i;j<=n;j+=i){
				sieve[j] = 0;
			}
		}
	}
 
}
 
vector<ll> findPrimeFact(ll n){
	vector<ll> ans;
	for(ll i=2LL;i*i<=n;i++){
		if(n%i==0){
			while(n%i==0){
				ans.push_back(i);
				n/=i;
			}
		}
	}
 
	if(n>1) ans.push_back(n);
	return ans;
}
 
vector<ll> findFactor(ll n){
	vector<ll> ans;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			ans.push_back(i);
			if(n/i!=i) ans.push_back(n/i);
		}
	}
 
	return ans;
}
 
bool isOdd(int n){
	return (n&1);
}
 
ll nCr(ll n, ll r){
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,0LL));
	dp[0][0]=1;
 
	for(ll i=1LL;i<=n;i++){
		dp[i][0]=1;
		if(i<=r) dp[i][i]=1;
		for(ll j=1LL;j<i;j++){
			dp[i][j]= dp[i-1][j-1]+dp[i-1][j];
		}
	}
    
	return dp[n][r];
}
 
 
int findParent(int node, vector<int>& parent){
	if(parent[node]==node) return node;
 
	return parent[node]=findParent(parent[node],parent);
}


int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    test{
		ll a,b;
		cin>>a>>b;

		if(a==1 && b==1){
			cout<<"Yes"<<endl;
			continue;
		}

		auto p1= findPrimeFact(a);
		auto p2= findPrimeFact(b);

		map<ll,ll> mp1,mp2;

		for(auto it: p1) mp1[it]++;
		for(auto it: p2) mp2[it]++;



		bool ans= true;
		for(auto it: mp1){
			ll diff= fabs(it.second-mp2[it.first]);
			ll miny= min(it.second,mp2[it.first]);

			if(miny-diff<0 || (miny-diff)%3!=0){
				ans=false;
				break;
			}
		}

		for(auto it: mp2){
			ll diff= fabs(it.second-mp1[it.first]);
			ll miny= min(it.second,mp1[it.first]);

			if(miny-diff<0 || (miny-diff)%3!=0){
				ans=false;
				break;
			}
		}

		if(ans) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

}