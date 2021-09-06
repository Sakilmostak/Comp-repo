#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,l,r;
        cin>>n>>l>>r;
        int base;
        if(r>=n && n>=l){
            base=n;
        }
        else{
            int ans=INT_MAX;
            for(ll i=l;i<=r;i++){
                if(i>=n){
                    base=i;
                }
                else{
                    ll p=n;
                    int sum=0;
                    while(p){
                        sum+=p%i;
                        p=p/i;
                    }

                    if(sum<ans){
                        ans=sum;
                        base=i;
                    }
                }
            
            }
        }
        
        cout<<base<<endl;
    }
}