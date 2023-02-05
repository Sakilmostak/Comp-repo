#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
#define ull unsigned long long
#define ll long long
#define mod 998244353
#define endl "\n"
#define test int t;cin>>t;while(t--)
#define limit 100000
#define setBit(x) __builtin_popcount(x)

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset;

ll euclidGcd(ll a, ll b){
	if(b==0){
		return a;
	}

	return euclidGcd(b, a%b);
}


ll modExp(ll a, ll b, ll c){
	if(a==0){
		return 0LL;
	}
	if(b==0){
		return 1LL;
	}
	
	if(b%2==1){
	    ll cur= modExp(a,b/2,c);
	    ll ans= (cur*cur)%mod;
	    ans= (ans*a)%mod;
	    
	    return ans;
	}
	else{
	    ll cur= modExp(a,b/2,c);
	    ll ans= (cur*cur)%mod;
	    
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


int makeSieve(int n){
    if(n<=1) return false;

	bool isPrime[n+1]={0};
	isPrime[0] = true;
	isPrime[1] = true;

	for(int i=2;i*i<=n;i++){
		if(isPrime[i] == true){
			for(int j=i*i;j<=n;j+=i){
				isPrime[j] = false;
			}
		}
	}

	int count = 0;
	for(int i=0;i<=n;i++){
		if(isPrime[i] == true){
			count++;
		}
	}
	return count;

}

vector<pair<ll,ll>> findPrimeFact(ll n){
	vector<pair<ll,ll>> ans;
	for(ll i=2LL;i*i<=n;i++){
		if(n%i==0){
			ll count=0LL;
			while(n%i==0){
				count++;
				n/=i;
			}
			ans.push_back({i,count});
		}
	}

	if(n>1) ans.push_back({n,1});
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

ll findMinIdx(vector<pair<ll,ll>>& dist, vector<bool>& visited){
	int idx=-1;
	for(int i=1;i<dist.size();i++){
		if(!visited[i] && (idx==-1 || dist[i].first<dist[idx].first)){
			idx=i;
		}
	}

	return idx;
}

vector<int> dijkstra(vector<vector<ll>>& edges, int n){
	vector<pair<ll,ll>> dist(n+1,{INT_MAX,-1});
	vector<bool> visited(n+1,0);
	dist[1]={0,-1};

	for(int i=0;i<n-1;i++){
		ll curIdx= findMinIdx(dist,visited);
		visited[curIdx]=1;
		for(auto it: edges){
			if(it[0]==curIdx){
				if(dist[curIdx].first+it[2]<dist[it[1]].first){
					dist[it[1]].first= dist[curIdx].first+it[2];
					dist[it[1]].second=curIdx;
				}
			}
		}
	}

	vector<int> ans;
	int prev=n;
	while(prev!=-1){
		ans.push_back(prev);
		prev=dist[prev].second;
	}

	reverse(ans.begin(),ans.end());

	return ans;
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

	int n,q,cmax;
	cin>>n>>q>>cmax;

	vector<vector<vector<int>>> dp(102,vector<vector<int>>(102,vector<int>(11,0)));

	for(int i=0;i<n;i++){
		int x,y,s;
		cin>>x>>y>>s;
		dp[x][y][s]++;
	}

	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			for(int k=0;k<=10;k++){
				dp[i][j][k]+=dp[i][j-1][k];
			}
		}
	}

	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			for(int k=0;k<=10;k++){
				dp[j][i][k]+=dp[j-1][i][k];
			}
		}
	}
	

	while(q--){
		int time,a,b,c,d;
		cin>>time>>a>>b>>c>>d;
		vector<int> cur(11,0);
		for(int i=0;i<=10;i++){
			cur[i]= dp[c][d][i]-dp[c][b-1][i]-dp[a-1][d][i]+dp[a-1][b-1][i];
		}
		
		int ans=0;
		
		for(int i=cmax;i>=0;i--){
		    
		    int val= (i+time)%(cmax+1);
			ans+=(val*cur[i]);

		}
		
		cout<<ans<<endl;

	}

}