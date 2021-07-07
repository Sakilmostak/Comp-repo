#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>

int main(){
    int n;
    cin>>n;

    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int preSum=0;
    map<int,int> count;

    for(int i=0;i<n;i++){
        preSum+= a[i];
        count[preSum]++;

    }

    int ans=0;

    map<int,int> :: iterator it;

    for(it= count.begin();it!= count.end();it++){
        int c= it->second;
        ans+= (c*(c-1))/2;

        if(it->first==0){
            ans+=it->second;
        }
    }

    cout<<ans<<endl;
}