#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int bsize=arr[0];
        int step=0;
        int bstep=0;

        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1]){
                step++;
            }
            else{
                if(arr[i]>bsize){
                    cout<<"-1"<<endl;
                }
                else{
                    bsize=arr[i];
                    bstep++;
                    step=0;
                }
            }
        }

        cout<<bstep+step<<endl;
    }
}