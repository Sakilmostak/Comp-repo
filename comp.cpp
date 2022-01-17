#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

void BFS(bool** adjgraph,bool* visited, int n, int startvalue);

void check(bool** adjgraph, bool* visited, int n){
	for(int i=0;i<n;i++){
		if(!visited[i]){
			BFS(adjgraph,visited,n,i);
		}
	}
}

void BFS(bool** adjgraph ,bool* visited,int n, int startvalue){
	queue<int> q;
	if(!visited[startvalue]){
		cout<<startvalue<<" ";
		visited[startvalue]=1;
		q.push(startvalue);
	}

	while(!q.empty()){
		int key=q.front();
		q.pop();
		for(int i=0;i<n;i++){
			if(adjgraph[key][i] && !visited[i]){
				cout<<i<<" ";
				q.push(i);
				visited[i]=1;
			}
		}
	}

	check(adjgraph,visited,n);
}


int main(){
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

  bool* visited= new bool[n]();
  BFS(adjgraph,visited,n,0);

}