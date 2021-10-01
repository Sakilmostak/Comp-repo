#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int pcheck[n+1]={0};
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int count=0;
        
        int k=0;
        
        while(k<2){
            for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                if(pcheck[arr[i]]<2 && pcheck[arr[i+1]]<2){
                    int temp=arr[i]^arr[i+1];
                    arr[i+1]=temp^arr[i+1];
                    arr[i]=temp^arr[i];
                    count++;
                    pcheck[arr[i]]++;
                    pcheck[arr[i+1]]++;
                }
            }
        }
            k++;
        }

        

        bool check=true;

        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                cout<<"NO"<<endl;
                check=false;
                break;
            }
        }

        if(check){
            cout<<"YES"<<endl;
            cout<<count<<endl;
        }
    }
}