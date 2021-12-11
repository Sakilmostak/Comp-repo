#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll phi[100002];
ll ans[100002];

int main(){
	for (int i = 1; i <= 100000; i++) {
        phi[i] = i;
    }
 
    for (int i = 2; i <= 100000; i++) {
        if (phi[i] == i) {
            phi[i] = i - 1;
            for (int j = 2 * i; j <= 100000; j += i) {
                phi[j] = (phi[j] * (i - 1)) / i;
            }
        }
    }
    
    for (int i = 1; i <= 100000; i++) {
 
        // Summation of d * ETF(d) where
        // d belongs to set of divisors of n
        for (int j = i; j <= 100000; j += i) {
            ans[j] += (i * phi[i]);
        }
    }

	int t;
	cin>>t;
	while(t--){
		ll n; 
        cin>>n;
		ll phisum=ans[n];

		phisum+=1; // to add the extra one to it.

		ll ans= (n*phisum)/2;

		cout<<ans<<endl;
		
	}
}