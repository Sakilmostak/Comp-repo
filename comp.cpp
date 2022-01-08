#include<bits/stdc++.h>
#define ull unsigned long long
#define MAX 1100001
#define mod 1000000007
#define ss(n) scanf("%lld", &n)
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ull arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr,arr+n,greater<int>());

        ull ans=0;

        for(int i=0;i<n;i++){
            ans+= (arr[i]*pow(2,i));
        }

        cout<<ans<<endl;
    }
}