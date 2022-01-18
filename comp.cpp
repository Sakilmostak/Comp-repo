#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;


int main(){
	int test;
    cin>>test;
    while(test--){
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
		map<int,int> mp;
		int v1,v2;
		cin>>v1>>v2;
		bool ans=false;

		queue<int> q;
		if(!visited[v1]){
			visited[v1]=1;
			q.push(v1);
		}

		while(!q.empty()){
			int key=q.front();
			q.pop();
			for(int i=0;i<n;i++){
				if(adjgraph[key][i] && !visited[i]){
					q.push(i);
					mp[i]=key;
					visited[i]=1;
					if(i==v2){
						ans=true;
					}
				}
			}
		}
		
		if(ans){
			int i=v2;
			cout<<v2<<" ";
			while(i!=v1){
				i=mp[i];
				cout<<i<<" ";
			}
		}
        cout<<endl;
	}


}