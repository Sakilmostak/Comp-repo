#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
#define test int t;cin>>t;while(t--)
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    test{
        ll x;
        cin>>x;
        
        bool check=0;

        ll curRange= sqrt(4+x)-2;
        
        for(ll i=1;i<=curRange;i++){
            ll num= x-(2*i);
            ll deno= i+2;
            if((num%deno)==0){
                check=1;
                break;
            }
        }
        
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }

    return 0;
}