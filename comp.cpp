#include<bits/stdc++.h>
#define ll long long
#define MAX 1100001
#define ss(n) scanf("%lld", &n)
using namespace std;

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

        sort(arr,arr+n);

        ll ans=INT_MAX;

        for(int i=1;i<n;i++){
            ans=min(ans, arr[i]-arr[i-1]);
        }

        cout<<ans<<endl;
    }
}