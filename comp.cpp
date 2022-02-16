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
		ll arr[2*n];
		for(int i=0;i<2*n;i++){
			cin>>arr[i];
		}
		
		ll tsum=0LL;
		for(int i=0;i<2*n;i++){
			tsum+=arr[i];
		}
		
		if(tsum%2==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}