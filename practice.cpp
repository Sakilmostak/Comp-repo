#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test int t;cin>>t;while(t--)



int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

	int n,m;
	cin>>n>>m;
	vector<vector<pair<ll,ll>>> adjList(n+1);
	for(int i=0;i<m;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		adjList[u].push_back({v,wt});
		adjList[v].push_back({u,wt});
	}

	vector<ll> dist(n+1,INT_MAX);
	vector<ll> parent(n+1,-1);
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

	pq.push({0,1});
	dist[1]=0;

	while(!pq.empty()){
		auto cur= pq.top();
		pq.pop();
		for(auto it: adjList[cur.second]){
			if(cur.first+it.second<dist[it.first]){
				dist[it.first]=cur.first+it.second;
				parent[it.first]=cur.second;
				pq.push({dist[it.first],it.first});
			}
		}

	}

	if(dist[n]==INT_MAX) cout<<-1<<endl;
	else{
		int prev=n;
		vector<int> ans;
		while(prev!=-1){
			ans.push_back(prev);
			prev=parent[prev];
		}
		reverse(ans.begin(),ans.end());
		for(auto it: ans) cout<<it<<" ";
		cout<<endl;
	}

    return 0;
}