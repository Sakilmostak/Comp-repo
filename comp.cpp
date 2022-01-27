#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int findMinDistIndex(bool* visited,int* dist, int n){
	int index=-1;
	for(int i=0;i<n;i++){
		if(!visited[i] && (index==-1 || dist[i]<dist[index])){
			index=i;
		}
	}

	return index;
}

void dijkastra(int** adjgraph,int n){
	int* dist= new int[n];
	bool* visited= new bool[n]();
	for(int i=0;i<n;i++){
		dist[i]=INT_MAX;
	}
	dist[0]=0;
	
	for(int i=0;i<n-1;i++){
		int minDistIndex= findMinDistIndex(visited,dist,n);
		visited[minDistIndex]=1;
		for(int j=0;j<n;j++){
			if(adjgraph[minDistIndex][j]!=0 && !visited[j] && dist[minDistIndex]+adjgraph[minDistIndex][j]<dist[j]){
				dist[j]=dist[minDistIndex]+adjgraph[minDistIndex][j];
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<i<<" "<<dist[i]<<endl;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,e;
		cin>>n>>e;
		int** adjgraph= new int*[n];
		for(int i=0;i<n;i++){
			adjgraph[i]= new int[n]();
		}

		for(int i=0;i<e;i++){
			int e1,e2,weight;
			cin>>e1>>e2>>weight;
			adjgraph[e1][e2]=weight;
			adjgraph[e2][e1]=weight;
		}

		dijkastra(adjgraph,n);
	}
}