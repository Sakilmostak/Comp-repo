#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll tNumExchange(int  arr[],int n, int value, ll** check){
	if(n<=0){
		return 0;
	}
	if(value==0){
		return 1;
	}
    if(value<0){
		return 0;
	}

	if(check[value][n]!=-1){
		return check[value][n];
	}

	ll first= tNumExchange(arr,n,value-arr[0],check)%mod;
	ll second= tNumExchange(arr+1,n-1,value,check)%mod;
	ll total= (first+second)%mod;
	if(check[value][n]==-1){
        check[value][n]=total;
    }

	return total;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int value;
		cin>>value;
		ll **check= new ll*[value+1];

		for(int i=0;i<=value;i++){
			check[i]= new ll[n+1];
		}

		for(int i=0;i<=value;i++){
			for(int j=0;j<=n;j++){
				check[i][j]=-1;
			}
		}
		ll ans= tNumExchange(arr,n,value,check);
        cout<<ans<<endl;
		
	}
}