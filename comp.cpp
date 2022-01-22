#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

// Union Find Algorithm to detect cycle in the graph
bool UnionFindAlgo(int* parent,int n,int u,int v){
	
	int fparent=parent[u];
	while(parent[fparent]!=fparent){
		fparent=parent[fparent];
	}
	int sparent=parent[v];
	while(parent[sparent]!=sparent){
		sparent=parent[sparent];
	}

	if(fparent!=sparent){
		int parentval=min(fparent,sparent);
		parent[fparent]=parentval;
		parent[sparent]=parentval;
		return true;
	}

	return false;
}

class edge{
	public:
	int u,v,weight;
};

bool comp(edge a,edge b){
	return a.weight<b.weight;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,e;
		cin>>n>>e;

		edge edges[e];
		for(int i=0;i<e;i++){
			cin>>edges[i].u>>edges[i].v>>edges[i].weight;
		}

		sort(edges,edges+e,comp);

		int* parent= new int[n];
		for(int i=0;i<n;i++){
			parent[i]=i;
		}

		int count=0;
		ll ans=0LL;
		for(int i=0;i<e;i++){
			if(UnionFindAlgo(parent,n,edges[i].u,edges[i].v)){
				count++;
				ans+=edges[i].weight;
			}
			if(count==n-1){
				break;
			}
		}

		cout<<ans<<endl;


	}
}