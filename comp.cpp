#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ff first
#define ss second

int main(){
    int n,k;
    cin>>n>>k;

    vi a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    map<int,int> freq;

    for(int i=0;i<n;i++){

        int presentSize= freq.size();
        if(freq[a[i]]==0 && presentSize== k){
            break;
        }
        
        freq[a[i]]++;
    }

    vector<pair<int,int>> ans;

    map<int,int> :: iterator it;
    for(it=freq.begin();it!= freq.end();it++){
        if(it->ss!=0){
            ans.push_back({it->ss, it->ff});
        }
    }

    sort(ans.begin(),ans.end(), greater<pair<int,int>>());

    vector<pair<int,int>> :: iterator it1;

    for(it1=ans.begin();it1!= ans.end();it1++){
        cout<<it1->ss<<" "<<it1->ff<<endl;
    }
}