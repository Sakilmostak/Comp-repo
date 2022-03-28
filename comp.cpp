#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int findMSB(ll n){
    if(n==0){
        return 0;
    }
    int ans=0;
    while(n>0){
        ans++;
        n=n/2;
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        ll msbcount[32]={0LL};
        for(int i=0;i<n;i++){
            int msb= findMSB(arr[i]);
            msbcount[msb]++;
        }

        ll pairs=0LL;
        for(int i=0;i<32;i++){
            pairs+=((msbcount[i]*(msbcount[i]-1))/2);
        }

        cout<<pairs<<endl;
    }
}