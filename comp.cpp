#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		ll arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		sort(arr,arr+n);

		vector<ll> target;
		target.push_back(0);
		ll sum=arr[0];

		for(int i=1;i<k;i++){
			target[0]=target[0]+(i*arr[i])-sum;
			sum+=arr[i];
		}

		for(int i=k;i<n;i++){
			target.push_back(target[i-k]+((k-1LL)*arr[i])+((k-1LL)*arr[i-k])-(2LL*(sum-arr[i-k])));
            sum-=arr[i-k];
			sum+=arr[i];
		}
        
        ll ans=target[0];

		for(int i=0;i<target.size();i++){
			ans=min(ans,target[i]);
            //cout<<target[i]<<" ";
		}
        cout<<ans<<endl;


	}
}