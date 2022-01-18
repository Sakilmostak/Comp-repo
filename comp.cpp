#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

void DFS(bool** adjgraph, bool* visited, int n, int startvalue){
	if(!visited[startvalue]){
		visited[startvalue]=1;
	}

	for(int i=0;i<n;i++){
		if(adjgraph[startvalue][i] && !visited[i]){
			DFS(adjgraph,visited,n,i);
		}
	}
}

bool isConnected(bool* visited,int n){
	for(int i=0;i<n;i++){
		if(!visited[i]){
			return false;
		}
	}

	return true;
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

		bool* visited= new bool[n]();
		DFS(adjgraph,visited,n,0);
		bool ans= isConnected(visited,n);
		if(ans){
			cout<<"true"<<endl;
		}
		else{
			cout<<"false"<<endl;
		}
		
	}


}