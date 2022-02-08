#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int findPalindromic(string s,int n){
	int ans=0;
    // for odd palindromic
	for(int i=0;i<n;i++){
		int pnum=1;
		int j=i-1;
		int k=i+1;
		while(k<n && j>=0 && s[j]==s[k]){
			pnum+=1;
			j--;k++;
		}

		ans+=pnum;
	}
    // for even palindromic
	for(int i=0;i<n-1;i++){
		if(s[i]==s[i+1]){
			int pnum=1;
			int j=i-1;
			int k=i+2;
			while(k<n && j>=0 && s[j]==s[k]){
				pnum+=1;
				j--;k++;
			}
			ans+=pnum;
		}
	}

	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n;
		n= s.size();

		int ans= findPalindromic(s,n);
		cout<<ans<<endl;
	}
}