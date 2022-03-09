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
        ll ans=0;
        ll maxy=0,miny=mod;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            x=(x>0)?x: -x;
            if(i%2==0){
                ans+=x;
                if(x<miny){
                    miny=x;
                }
            }
            else{
                ans-=x;
                if(x>maxy){
                    maxy=x;
                }
            }
        }
        
        if(maxy>miny){
            ans+=(2*(maxy-miny));
        }
        cout<<ans<<endl;
    }
}