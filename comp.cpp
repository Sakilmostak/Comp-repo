#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr,arr+n);

        ll dp[n]={0};
        int count=0;

        for(int i=0;i<n;i++){
            count++;
            if(count==arr[i]){
                dp[i]=count;
                count=0;
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            if(dp[i]!=0){
                ans++;
            }
        }

        cout<<ans<<endl;
    }
}