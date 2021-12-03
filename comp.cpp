#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long


int main(){
	bool arr[1000001]={0};
	for(int i=2;i<=100;i++){
        for(ll j=1;j*pow(i,3)<=1000000;j++){
            ll index= j*pow(i,3);
            arr[index]=1;
        }
    }
    
    ll countpos[1000001]={0};
    ll count=0;
    for(ll i=1;i<1000001;i++){
        if(arr[i]==0){
            count++;
            countpos[i]=count;
        }
        else{
            countpos[i]=0L;
        }
    }
    
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        
        if(countpos[n]==0){
            cout<<"Not Cube Free"<<endl;
        }
        else{
            cout<<countpos[n]<<endl;
        }
    
    }

}