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

        vector<int> ans;
        ans= arr;
        sort(arr.begin(),arr.end());

        map<int,int> mp;
        int count=0;
        for(int i=n-1;i>=0;i--){
            if(count<k){
                mp[arr[i]]=1;
                count++;
            }
            else{
                break;
            }
        }

        vector<int> rep;

        for(int i=0;i<n;i++){
            if(mp[ans[i]]==1){
                rep.push_back(ans[i]);
            }
        }

        vector<int> realAns;
        realAns=rep;

        sort(rep.begin(),rep.end());

        cout<<rep[(k-1)/2]<<endl;

        for(auto i: realAns){
            cout<<i<<" ";
        }
        cout<<endl;



        
    }
}