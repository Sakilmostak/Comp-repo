#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    if(p1.first!=p2.first){
        return p1.first>p2.first;
    }

    return p1.second<p2.second;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        if(x==0){
            map<ll,int> mapy;

            for(int i=0;i<n;i++){
                mapy[arr[i]]++;
            }

            map<ll,int> :: iterator ita;
            int maxfreq=0;

            for(ita= mapy.begin();ita!=mapy.end();ita++){
                if(ita->second>maxfreq){
                    maxfreq=ita->second;
                }
            }

            cout<<maxfreq<<" "<<"0"<<endl;
        }
        else{

        map<ll,int> mp;
        map<ll,int> freq;


        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            mp[arr[i]^x]++;
            freq[arr[i]^x]++;
        }


        map<ll,int> :: iterator it;
        vector<pair<int,int>> ans;

        for(it=mp.begin();it!=mp.end();it++){
            pair<int,int> temp;
            temp.first=it->second;
            temp.second=freq[it->first];
            ans.push_back(temp);
        }

        sort(ans.begin(),ans.end(),compare);

        cout<<ans[0].first<<" "<<ans[0].second<<endl;
        }
    }
}