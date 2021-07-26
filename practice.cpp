#include<bits/stdc++.h>

using namespace std;

int run_bfs(int s, vector<vector<int>> & adjList, vector<bool> & visited){
	queue<int> Q;
	Q.push(s);
	visited[s]= true;
	int node_count=0;
	while(!Q.empty()){
		s=Q.front();
		Q.pop();
		node_count+=1;

		for(int adjNode: adjList[s]){
			if(!visited[adjNode]){
				visited[adjNode]=true;
				Q.push(adjNode);
			}
		}
	}

	return node_count;
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