#include<bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr.begin(), arr.end());

        int kw1=0,aw1=0;

        for(int i=0;i<n;i++){
            if(i<k){
                kw1+=arr[i];
            }
            else{
                aw1+=arr[i];
            }
        }

        int kw2=0, aw2=0;

        for(int i=n-1;i>=0;i++){
            if(k){
                kw2+=arr[i];
                k--;
            }
            else{
                aw2+=arr[i];
            }
        }

        int ans= max((aw1-kw1),(kw2-aw2));

        cout<<ans<<endl;

        
    }

    return 0;
}