#include<bits/stdc++.h>
#define ll int long long

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        if(k>0){
            
            cout<<n/k<<" "<<n%k<<endl;
        }
        else{
            cout<<"0"<<" "<<n<<endl;
        }
        
    }
}