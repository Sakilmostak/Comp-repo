#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

bool comp(pair<ll,ll> f, pair<ll,ll> s){
    double fr = f.first/(f.second+0.0);
    double sr = s.first/(s.second+0.0);

    return fr>sr;

}

int main(){
    ll n;
    cin>>n;
    ll w;
    cin>>w;
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
    ll i=0;
    double totalvalue=0;

    while(w>0 && i<n){
        if(w-arr[i].second>=0){
            totalvalue+=arr[i].first;
            w=w-arr[i].second;
        }
        else{
            if(w>0)
            {double curvalue= (arr[i].first/(arr[i].second+0.0))*w;
            totalvalue+=curvalue;
            break;}
        }

        i++;
    }

    cout<<setprecision(6)<<fixed<<totalvalue<<endl;

    

}