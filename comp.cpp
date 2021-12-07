#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

bool primes[1000001];

map<int,int> factors(int n){
    map<int,int> mp;
    ll i=1;
    
    while(n>1 && i<sqrt(n)){
        i++;
        while(primes[i]==0 && n%i==0 && n>=1){
            n=n/i;
            mp[i]++;
        }
    }

    if(n>1 && primes[n]==0){
        mp[n]++;
    }

    return mp;
}




int main(){
	int n;
    cin>>n;

    bool arr[n+1]={0};
    arr[0]=1;

    for(int i=n;i>=1;i--){
        if(arr[i]==0){
            map<int,int> mp = factors(i);
            map<int,int> :: iterator it;
            vector<int> pr;
            for(it=mp.begin();it!=mp.end();it++){
                int x=i;
                while(x>1){
                   if(arr[x]==0){
                       arr[x]=1;
                       pr.push_back(x);
                   }
                   x-=it->first;
                }
            }
            sort(pr.begin(),pr.end(),greater<int>());
            for(int j=0;j<pr.size();j++){
                cout<<pr[j]<<" ";
            }
        }
        
    }
    cout<<"1 "<<endl;
}