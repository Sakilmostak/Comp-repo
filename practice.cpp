#include<bits/stdc++.h>

using namespace std;

int inTime[1000];
int outTime[1000];

int inT=0,outT=0;

int dfs(int s, vector<vector<int>> & adjList, vector<bool> & visited){
	visited[s]=true;
	inTime[s]=inT;
	inT++;

	for(int adjNode: adjList[s]){
		if(!visited[adjNode]){
			dfs(adjNode, adjList, visited);
		}
	}
	outTime[s]=outT;
	outT++;
}

int main(){
	int n; // no of vertices
	int m; // no of edges

	cin>>n>>m;

	vector<vector<int>> adjList(n);  // Adjacency List representation of Graph

	for(int i=0;i<m;i++){
		int from, to;
		cin>>from>>to;
		adjList[from].push_back(to);
	}


	const int INF = 100000000;

	vector<bool> visited(n, false);
	
	// to find the number of connected components
	int conn_comp_count=0;
	for(int nd=0;nd<n;nd++){
		if(!visited[nd]){
			//run a BFS
			conn_comp_count+=1;
			int node_count= run_bfs(nd,adjList,visited);
			cout<<"We ran BFS from "<<nd<<", node-count = "<<node_count<<endl;
		}
	}

	cout<<"\n Total "<<conn_comp_count<<" Connected Components"<<endl;
	

	return 0;
}