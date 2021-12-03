#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }

    return gcd(b, a%b);
}

int main(){
	int t;
    cin>>t;
    while(t--){
       ll a;
       cin>>a;
       string b;
       cin>>b;

       ll modans=0;

       for(int i=0;i<b.length();i++){
           int digit=b[i]-'0';
           modans= (((modans*10)%a)+(digit%a))%a;
       }

       ll ans = gcd(a, modans);

       cout<<ans<<endl;
    }
}