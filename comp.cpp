#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int** adjgraph= new int*[n+1];
		for(int i=0;i<=n;i++){
			adjgraph[i]=new int[n+1];
			for(int j=0;j<=n;j++){
				adjgraph[i][j]=1e9;
			}
		}

		for(int i=0;i<m;i++){
			int src;
			int des;
			int weight;
			cin>>src>>des>>weight;
			adjgraph[src][des]=min(adjgraph[src][des],weight);
			adjgraph[des][src]=min(adjgraph[des][src],weight);
		}

		//bellman ford algorithm
		int dist[n+1][n+1];
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				dist[i][j]=adjgraph[i][j];
			}
		}

		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dist[i][k]!=1e9 && dist[k][j]!=1e9 && dist[i][k]+dist[k][j]<dist[i][j]){
						dist[i][j]=dist[i][k]+dist[k][j];
					}
				}
			}
		}

		//queries
		int q;
		cin>>q;
		for(int i=0;i<q;i++){
			int u,v;
			cin>>u>>v;
			if(u==v){
				cout<<0<<endl;
			}
			else{
				cout<<dist[u][v]<<endl;
			}
		}
	}
}