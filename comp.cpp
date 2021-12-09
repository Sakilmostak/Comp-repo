#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n; 
        cin>>n;
		ll tot = n;
		for (ll p = 2; p*p <= n; p++)
		{
    		if (n%p==0)
    		{
        		tot /= p;
        		tot *= (p-1);
        		while ( n % p == 0 ) 
            		n /= p;
    		}
		}
        
		if ( n > 1 ) {
    		tot /= n;
    		tot *= (n-1);
		}
        
        cout<<tot<<endl;
	}
}