#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long


int main(){
	int t;
	cin>>t;
	while(t--){
		string m,w;
		cin>>m>>w;

		bool flag= 0;
		int j=0;

		for(int i=0;i<m.size();i++){
			if(w[j]==m[i]){
				j++;
			}
		}

		if(j==w.size()){
			flag=1;
		}

		j=0;

		for(int i=0;i<w.size();i++){
			if(m[j]==w[i]){
				j++;
			}
		}

		if(j==m.size()){
			flag=1;
		}

		if(flag){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}

	}

}