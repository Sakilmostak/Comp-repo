#include<bits/stdc++.h>
#define ll int long long

using namespace std;

int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int n= n1+n2+n3;
    map<int, int> mp;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }

    int count=0;
    vector<int> a;

    map<int,int> :: iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        if(it->second>=2){
            count++;
            a.push_back(it->first);
        }
    }

    cout<<count<<endl;
    for(auto i: a){
        cout<<i<<endl;
    }
    return 0;
}