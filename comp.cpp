#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

class triplets{
    public:
    ll x;
    ll y;
    ll gcd;
};

triplets gcdExtendedEuclid(ll a, ll b){
    if(b==0){
        triplets ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;
    }

    triplets getans= gcdExtendedEuclid(b, a%b);

    triplets ans;
    ans.gcd=getans.gcd;
    ans.x= getans.y;
    ans.y= getans.x- ((a/b)*(getans.y));
    return ans;
}

ll mMInverse(ll a, ll m){
    ll ans= gcdExtendedEuclid(a,m).x;
    return (ans%m + m)%m;  //to handle negative values
}

int main(){
	int t;
    cin>>t;
    while(t--){
        ll a,b,d;
        cin>>a>>b>>d;

        ll g= __gcd(a,b); //predefined func to find gcd
        if(d%g){
            cout<<0<<endl;
            continue;
        }
        if(d==0){
            cout<<1<<endl;
            continue;
        }
        a/=g;
        b/=g;
        d/=g;

        ll y1= ((d%a)* mMInverse(b,a))%a;
        ll firstValue= d/b;

        if(d<y1*b){
            cout<<0<<endl;
            continue;
        }

        ll n = (firstValue-y1)/a;

        ll ans= n+1;
        cout<<ans<<endl;

    }
}