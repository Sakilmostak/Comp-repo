#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

bool totalPathDFS(bool** adjgraph,bool* visited,int n, int v1,int v2){
	if(v1==v2){
        cout<<v2<<" ";
		return true;
	}
	visited[v1]=1;
	for(int i=0;i<n;i++){
		if(adjgraph[i][v1] && !visited[i]){
			if(i==v2){
                cout<<i<<" ";
				return true;
			}
			bool check=totalPathDFS(adjgraph,visited,n,i,v2);
			if(check){
                cout<<i<<" ";
				return true;
			}
		}
	}

	return false;
}


int main(){

	int t;
	cin>>t;
	while(t--){
		int n,e;
		cin>>n>>e;

		bool** adjgraph= new bool* [n];
		for(int i=0;i<n;i++){
			adjgraph[i]= new bool[n];
			for(int j=0;j<n;j++){
				adjgraph[i][j]=0;
			}
		}

		for(int i=0;i<e;i++){
			int a,b;
			cin>>a>>b;
			adjgraph[a][b]=1;
			adjgraph[b][a]=1;
		}

		int v1,v2;
		cin>>v1>>v2;

		bool* visited= new bool[n]();
		bool ans=totalPathDFS(adjgraph,visited,n,v1,v2);
        if(ans){
            cout<<v1<<" ";
        }
        cout<<endl;
		
	}
}