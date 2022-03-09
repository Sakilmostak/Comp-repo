#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    ll arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<m;i++){
        int c,x;
        cin>>c>>x;
        for(int i=0;i<x;i++){
            int wi,civ;
            cin>>wi>>civ;
            arr[civ]= ((arr[civ])%mod+ (wi*arr[c])%mod)%mod;
        }
        arr[c]=0;
    }

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<endl;
    }
}