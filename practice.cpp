#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		char** arr = new char*[n];
		for(int i=0;i<n;i++){
			arr[i]= new char[n];
		}

		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			for(int j=0;j<n;j++){
				arr[i][j]=s[j];
			}
		}

		bool** visited= new bool*[n];
		for(int i=0;i<n;i++){
			visited[i]=new bool[n];
			for(int j=0;j<n;i++){
				visited[i][j]=0;
			}
		}

		int ans=0;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;i++){
                cout<<visited[i][j];
			}
            cout<<endl;
		}

		cout<<ans<<endl;
	}
}