#include<bits/stdc++.h>
#define ll int long long

using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
       ll n,k;
       cin>>n>>k;
       ll si= pow(2,n);
       ll arr[si];
       for(ll i=0;i<si;i++){
           arr[i]=i;
       }
       for(ll i=0;i<k;i++){
           ll temp=arr[i];
           arr[i]= arr[n-1-i];
           arr[n-1-i]=temp;
       }

       ll ans=0;
       for(ll i=0;i<k;i++){
           arr[i]= arr[i]^i;
           arr[n-1-i]= arr[n-1-i]^(n-1-i);
           ans= ans+ arr[i]+ arr[n-1-i];

       }

       cout<<ans<<endl;
    }
}