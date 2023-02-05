#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // for policy based data structures
#include<ext/pb_ds/tree_policy.hpp> // for policy based data structures
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
#define test int t;cin>>t;while(t--)
#define limit 100000
#define countBit(x) __builtin_popcount(x)

using namespace std;
using namespace __gnu_pbds; // for policy based data structures

typedef tree<int, null_type, less<int>, rb_tree_tag, // set using pbds
    tree_order_statistics_node_update>
    ordered_set;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, // multiset using pbds
    tree_order_statistics_node_update>
    ordered_multiset;

// find_by_order : to find the element will be at that index if it was sorted O(logn)
// order_of_key : to find the number of elements smaller that the given key O(logn)

bool isOdd(int n){
	return (n&1);
}

ll setBit(ll n, int idx){
	ll mask= (1LL<<idx);
	return (n|mask);
}

ll clearBitRange(ll n, int l, int r){
	int mask= (~0);
	mask= mask<<(l+1);
	int submask= (1LL<<r)-1;
	mask= mask|submask;

	return (n&mask);
}

ll lsb(ll n){ // least significant bit
	return (n^(n&(n-1)));
}

ll euclidGcd(int a, int b){
	if(b==0){
		return a;
	}

	return euclidGcd(b, a%b);
}

ll fastExp(ll n, int x){
	ll ans=1LL;
	while(x){
		int lbit= (x&1);
		if(lbit) ans= (ans*n)%mod;
		n*=n;
		x>>=1;
	}

	return ans;
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

// finding prime in a range
int makeSieve(int n){
    if(n<=1) return false;

	vector<int> isPrime(n+1,true);
	isPrime[0] = false;
	isPrime[1] = false;

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

// finding Fibionacci seqeuenece Complexity: O(logn*loglogn)
ll fastFib(ll n, unordered_map<ll,ll> dp){
	if(dp.count(n)) return dp[n];

	ll k= n/2;
	if(n%2==0){
		return dp[n]= (fastFib(k,dp)*fastFib(k,dp) + fastFib(k-1,dp)*fastFib(k-1,dp))%mod;
	}
	else{
		return dp[n]= (fastFib(k,dp)*fastFib(k+1,dp) + fastFib(k-1,dp)*fastFib(k,dp))%mod;
	}
}

// finding all prime factors of a number
void findFactor(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			cout<<i<<endl;
			while(n%i==0) n/=i;
		}
	}

	if(n>1) cout<<n<<endl;
}

// Disjoint Set Union with Path Compression and Union Ranking
class DSNode{
	public:
	int data;
	DSNode* parent;
	int rank;
};

class DisjointSet{
	private:
	map<int,DSNode*> hash;

	DSNode* searchInSetHelper(DSNode* node){
		if(node == node->parent){
			return node;
		}

		node->parent = searchInSetHelper(node->parent);
		return node->parent;
	}

	public:

	void initializeSet(int data){
		DSNode* node = new DSNode();
		node->data= data;
		node->parent= node;
		node->rank= 0;
		hash[data]= node;
	}

	void Union(int data1,int data2){
		DSNode* node1= hash[data1];
		DSNode* node2= hash[data2];

		DSNode* parent1= searchInSetHelper(node1);
		DSNode* parent2= searchInSetHelper(node2);

		if(parent1->data==parent2->data){
			return;
		}

		if(parent1->rank>=parent2->rank){

			if(parent1->rank==parent2->rank){
				parent1->rank= parent2->rank+1;
			}
			
			parent2->parent=parent1;
		}
		else{
			parent1->parent=parent2;
		}
	}

	int searchInSet(int data){
		return searchInSetHelper(hash[data])->data;
	}
    
    void clearSet(){
        for(auto it: hash){
            delete it.second;
        }
        
        hash.clear();
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    test{

    }

    return 0;
}