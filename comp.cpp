#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

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
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int m;
	cin>>m;
	edge edges[m+n];
	for(int i=0;i<m;i++){
		cin>>edges[i].u;
		cin>>edges[i].v;
		int a,b;
		cin>>a>>b;
		edges[i].weight= a+b;
	}

	for(int i=m;i<m+n;i++){
		edges[i].u=i-m;
		edges[i].v=n;
		edges[i].weight= arr[i-m];

	}

	sort(edges,edges+n+m,comp);

	int* parent=new int[n+1];
	for(int i=0;i<=n;i++){
		parent[i]=i;
	}

	int count=0;
	ll ans=0LL;
	for(int i=0;i<n+m;i++){
		if(UnionFindAlgo(parent,n+1,edges[i].u,edges[i].v)){
			count++;
			ans+=edges[i].weight;
		}
		if(count==n){
			break;
		}
	}

	cout<<ans<<endl;
}