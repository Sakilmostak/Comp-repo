#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n,s;
        cin>>n>>s;

        ll sum = (n*(n+1))/2;
        int ans=-1;

        int start=1;
        int end=n;

        while(start<=end){
            ll mid= (start+end)/2;
            if(sum-mid==s){
                ans=mid;
                break;
            }
            else if(sum-mid<s){
                end=mid-1;
            }
            else if(sum-mid>s){
                start=mid+1;
            }
        }

        cout<<ans<<endl;
    }
}