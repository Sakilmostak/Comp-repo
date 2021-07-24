#include<bits/stdc++.h>
#define ll int long long

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll m,n;
    cin>>m>>n;
    if(m<=2){
        cout<<"2"<<endl;
    }

    for(ll i=m;i<=n;i++){
        if(i%2==1){
            bool check=true;
            for(ll j=3;j<=sqrt(i);j+=2){
                if(i%j==0){
                    check=false;
                    break;
                }
            }
            if(check && i!=1){
                cout<<i<<endl;
            }
        }
    }

    cout<<endl;
    }

    return 0;
}