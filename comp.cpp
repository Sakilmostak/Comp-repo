#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        } 

        // finding LIS till that index

        vector<int> lis, prefix(n);
        for(int i=0;i<n;i++){
            auto it=lower_bound(lis.begin(),lis.end(),v[i])-lis.begin();
            if(it==lis.size()){
                lis.push_back(v[i]);
            }
            else{
                lis[it]= v[i];
            }

            prefix[i]=lis.size();
        }

        lis.clear();

        // finding LIS possible after that index

        vector<int> suffix(n);
        for(int i=n-1;i>=0;i--){
            auto it= lower_bound(lis.begin(),lis.end(),-v[i])-lis.begin();
            if(it==lis.size()){
                lis.push_back(-v[i]);
            }
            else{
                lis[it]=-v[i];
            }
            suffix[i]=lis.size();
        }

        //LIS possible by performing operation in an subarray at that index is prefix[i-1]+suffix[i]

        int ans=suffix[0];

        for(int i=1;i<n;i++){
            ans=max(ans, prefix[i-1]+suffix[i]);
        }

        cout<<ans<<endl;
        
    }
}