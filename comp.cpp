#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long


int main(){
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[100001]={0};
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr[x]=1;
        }

        for(int i=1;i<=100000;i++){
            if(arr[i]>=1){
                for(int j=2*i;j<=100000;j+=i){
                    if(arr[j]>=1){
                        arr[j]+=arr[i];
                    }
                }
            }
        }

        ll count=0;

        for(int i=1;i<=100000;i++){
            count+=arr[i];
        }

        cout<<count<<endl;

    }

}