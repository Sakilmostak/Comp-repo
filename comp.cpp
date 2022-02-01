#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

class directedEdge{
	public:
	int a,b,weight;
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,src,des;
		cin>>n>>m;
		cin>>src>>des;

		directedEdge diredge[m];

		for(int i=0;i<m;i++){
			cin>>diredge[i].a;
			cin>>diredge[i].b;
			cin>>diredge[i].weight;
		}

		int arr[n];

		for(int i=0;i<n;i++){
			arr[i]= 100001;
		}

		arr[src]=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(arr[diredge[j].a]+diredge[j].weight<arr[diredge[j].b]){
					arr[diredge[j].b]=arr[diredge[j].a]+diredge[j].weight;
				}
			}
		}

		bool check=true;

		for(int i=0;i<m;i++){
			if(arr[diredge[i].a]+diredge[i].weight<arr[diredge[i].b]){
				check=false;
			}
		}

		if(check){
			cout<<arr[des]<<endl;
		}




	}
}