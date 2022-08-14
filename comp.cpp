#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
#define test int t;cin>>t;while(t--)
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    test{
        ll n,x,y;
        cin>>n>>x>>y;

        priority_queue<ll,vector<ll>, greater<ll>> pq;
        for(ll i=0;i<n;i++){
            ll now;
            cin>>now;
            pq.push(now);
        }
        
        if(y<=n){
            for(ll i=0;i<y;i++){
                ll cur= pq.top();
                pq.pop();
                pq.push(cur^x);
            }
            
            for(ll i=0;i<n;i++){
                cout<<pq.top()<<" ";
                pq.pop();
            }
            cout<<endl;
        }
        else{
            int count=0;

            for(ll i=0;i<n;i++){
                ll cur= pq.top();
                pq.pop();
                pq.push(cur^x);
                count++;
                if((cur^x)<cur){
                    break;
                }
            }
            
            y-=count;
            y= y&1;
            
            if(y==1){
                ll cur= pq.top();
                pq.pop();
                pq.push(cur^x);
            }
    
            for(ll i=0;i<n;i++){
                cout<<pq.top()<<" ";
                pq.pop();
            }
            cout<<endl;
        }
        
        
    }

    return 0;
}