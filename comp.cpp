#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,l;
        cin>>n>>k>>l;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        if(k>0){
            arr[n-1]+=(k*(l-1));
        }

        int maxSpeed=0;
        int count=1;

        for(int i=0;i<n;i++){
            if(arr[i]>maxSpeed){
                maxSpeed=arr[i];
                count=1;
            }
            else if(arr[i]==maxSpeed){
                count++;
            }
        }

        if(arr[n-1]==maxSpeed && count==1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}