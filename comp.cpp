#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

bool comp(pair<ll,ll> f, pair<ll,ll> s){
    if(f.second==s.second){
        return f.first<s.first;
    }

    return f.second<s.second;

}

int main(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr;
    for(int i=0;i<n;i++){
        pair<ll,ll> x;
        cin>>x.first;
        cin>>x.second;
        arr.push_back(x);
    }

    sort(arr.begin(),arr.end(),comp);

    /*for(int i=0;i<n;i++){
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }*/

    ll finish=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(arr[i].first>=finish){
            ans++;
            finish=arr[i].second;
        }
    }

    cout<<ans<<endl;

}