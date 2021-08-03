#include<bits/stdc++.h>
#define ll int long long

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> div;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                div.push_back(i);
            }
        }
        
        int s= div.size();
        
        int ans=INT_MAX;
        for(int i=0;i<s;i++){
            ans= min(abs(div[i]-div[s-1-i]),ans);
        }
        
        cout<<ans<<endl;

    }
}