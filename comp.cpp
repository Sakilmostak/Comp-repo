#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

// Algo to find minimum weighted vertex which is not 
int findMinVert(bool* visited,int* weight, int n){
	int minVertex=-1;
	for(int i=0;i<n;i++){
		if(!visited[i] && (minVertex==-1 || weight[minVertex]>weight[i])){
			minVertex=i;
		}
	}

	return minVertex;

}

//prim's algo to find MST
int prims(int** adjgraph, int n){
	bool* visited= new bool[n];
	int* parent= new int[n];
	int* weight= new int[n];

	for(int i=0;i<n;i++){
		weight[i]=INT_MAX;
	}

	weight[0]=0;
	parent[0]=-1;

	for(int i=0;i<n-1;i++){
		int minVertex= findMinVert(visited,weight,n);
		visited[minVertex]=true;
		for(int j=0;j<n;j++){
			if(adjgraph[minVertex][j]!=0 && !visited[j]){
				if(weight[j]>adjgraph[minVertex][j]){
					weight[j]=adjgraph[minVertex][j];
					parent[j]=minVertex;
				}
			}
		}
	}

	int totalsum=0;

	for(int i=1;i<n;i++){
		totalsum+=weight[i];
	}

	delete[] parent;
	delete[] weight;
	delete[] visited;

	return totalsum;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,e;
		cin>>n>>e;
		int** adjgraph= new int*[n];
		for(int i=0;i<n;i++){
			adjgraph[i]=new int[n];
			for(int j=0;j<n;j++){
				adjgraph[i][j]=0;
			}
		}

		for(int i=0;i<e;i++){
			int u,v,weight;
			cin>>u>>v>>weight;
            
			adjgraph[u][v]=weight;
			adjgraph[v][u]=weight;

		}
        
		int ans=prims(adjgraph,n);
		cout<<ans<<endl;
		
		for(int i=0;i<n;i++){
			delete[] adjgraph[i];
		}

		delete[] adjgraph;
		}
}