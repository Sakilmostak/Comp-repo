#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
#define test int t;cin>>t;while(t--)
using namespace std;

bool check(int x,int y,int n,int m){
    if(x>=0 && x<n && y>=0 && y<m) return true;
    
    return false;
}

void dfs(vector<vector<ll>>& arr, int x, int y, int n, int m,vector<vector<bool>>& visited, unordered_map<ll,ll>& mp){
    
    visited[x][y]=1;
    
    mp[arr[x][y]]++;
    
    int dirX[] = {-1,-1,1,1};
    int dirY[] = {-1,1,-1,1};
    
    for(int i=0;i<4;i++){
        int newX= x+dirX[i];
        int newY= y+dirY[i];
        
        if(check(newX,newY,n,m) && !visited[newX][newY]){
            dfs(arr,newX,newY,n,m,visited,mp);
        }
    }
}

bool helper(vector<vector<ll>>& a, vector<vector<ll>>& b, int x, int y, vector<vector<bool>>& visited){
    
    unordered_map<ll,ll> mp1,mp2;
    int n=a.size();
    int m=a[0].size();
    
    dfs(a,x,y,n,m,visited,mp1);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=0;
        }
    }
    
    dfs(b,x,y,n,m,visited,mp2);
    
    for(auto it: mp1){
        if(mp2[it.first]!=it.second) return true;
    }
    
    return false;
    
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    test{
        int n,m;
        cin>>n>>m;
        vector<vector<ll>> a(n,vector<ll>(m));
        vector<vector<ll>> b(n,vector<ll>(m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>b[i][j];
            }
        }
        
        bool ans=false;
        
        if(n==1 && m==1){
            if(a[0][0]!=b[0][0]) ans=true;
        }
        else if(n==1 || m==1){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(a[i][j]!=b[i][j]){
                        ans=true;
                        break;
                    }
                }
                if(ans) break;
            }
        }
        else{
            vector<vector<bool>> visited(n,vector<bool>(m,0));
            
            ans= helper(a,b,0,0,visited) || helper(a,b,0,1,visited);
            
        }
        
        
        
        if(ans) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}