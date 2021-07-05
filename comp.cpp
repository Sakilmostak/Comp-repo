#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    while(t--)
        {int n;
        cin>>n;
        int arr[n];
        int Max= INT_MIN;
        int Min= INT_MAX;

        for(int i=0;i<n;i++){
            cin>>arr[i];
            Max= max(Max,arr[i]);
            Min= min(Min, arr[i]);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            if(arr[i]==Max){
                ans++;
            }
            else{
                ans+= arr[i]/Min;
            }

        }

        cout<<ans<<endl;
    }

}