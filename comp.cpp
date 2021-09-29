#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int n;
    cin>>n;
    ll xcost,ycost;
    cin>>xcost>>ycost;
    string bulb;
    cin>>bulb;
    
    int count=0;
    bool check=true;
    for(int i=0;i<n;i++){
        if(bulb[i]=='0'){
            check=false;
        }
    }
    for(int i=0;i<n-1;i++){
        if(bulb[i]=='0' && bulb[i+1]=='1'){
            count++;
        }
    }
    
    if(check){
        cout<<"0"<<endl;
    }
    else{
        int xcount=count;
        int ycount=count+1;
        if(bulb[n-1]=='1'){
            xcount--;
            ycount--;
        }
        
        ll ans1=(xcount*xcost)+ycost;
        ll ans2=(ycount*ycost);
        cout<<min(ans1,ans2)<<endl;
    }

    
}