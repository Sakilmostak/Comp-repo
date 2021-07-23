#include<bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        int miny=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            miny= min(miny, arr[i]);
            sum+=arr[i];
        }

        if(sum%k>=miny){
            cout<<"-1"<<endl;
        }
        else{
            cout<<sum/k<<endl;
        }
    }
}