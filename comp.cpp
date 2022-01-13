#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

struct enemy{
    public:
    ll a;
    ll b;
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        struct enemy arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i].a;
            cin>>arr[i].b;
        }

        ll dp[n];
        dp[0]=arr[0].a-arr[n-1].b;

        for(int i=1;i<n;i++){
            dp[i]=arr[i].a-arr[i-1].b;
        }

        ll total=0;

        for(int i=0;i<n;i++){
            if(dp[i]>0){
                total+=dp[i];
            }
        }

        ll ans[n];

        for(int i=0;i<n;i++){
            ans[i]=total;
            if(dp[i]>0){
                ans[i]-=dp[i];
            }

            ans[i]+=arr[i].a;
            
        }

        ll crrans=INT64_MAX;

        for(int i=0;i<n;i++){
            crrans= min(crrans, ans[i]);
        }

        cout<<crrans<<endl;


    }
}