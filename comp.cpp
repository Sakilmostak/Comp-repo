#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

bool checklimit(int i, int j,int n){
	if(i>=0 && i<n && j>=0 && j<n){
		return true;
	}

	return false;
}

int findLargestPcs(char** arr, bool** visited,int n,int i, int j){
	if(visited[i][j] || arr[i][j]=='0'){
        return 0;
    }
    
    visited[i][j]=1;

	int count=1;

	if(checklimit(i,j+1,n) && !visited[i][j+1] && arr[i][j+1]=='1'){
		count+=findLargestPcs(arr,visited,n,i,j+1);
	}
	if(checklimit(i,j-1,n) && !visited[i][j-1] && arr[i][j-1]=='1'){
		count+=findLargestPcs(arr,visited,n,i,j-1);
	}
	if(checklimit(i+1,j,n) && !visited[i+1][j] && arr[i+1][j]=='1'){
		count+=findLargestPcs(arr,visited,n,i+1,j);
	}
	if(checklimit(i-1,j,n) && !visited[i-1][j] && arr[i][j]=='1'){
		count+=findLargestPcs(arr,visited,n,i-1,j);
	}

	/*if(checklimit(i+1,j+1,n) && !visited[i+1][j+1] && arr[i+1][j+1]=='1'){
		count+=findLargestPcs(arr,visited,n,i+1,j+1);
	}
	if(checklimit(i-1,j-1,n) && !visited[i-1][j-1] && arr[i-1][j-1]=='1'){
		count+=findLargestPcs(arr,visited,n,i-1,j-1);
	}
	if(checklimit(i+1,j-1,n) && !visited[i+1][j-1] && arr[i+1][j-1]=='1'){
		count+=findLargestPcs(arr,visited,n,i+1,j-1);
	}
	if(checklimit(i-1,j+1,n) && !visited[i-1][j+1] && arr[i-1][j+1]=='1'){
		count+=findLargestPcs(arr,visited,n,i-1,j+1);
	}
    */
    
	return count;
}

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
			for(int j=0;j<n;j++){
				visited[i][j]=0;
			}
		}

		int ans=0;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!visited[i][j] && arr[i][j]=='1'){
					int newsize= findLargestPcs(arr,visited,n,i,j);
					ans=max(newsize,ans);
				}
			}
		}
        

		cout<<ans<<endl;
	}
}