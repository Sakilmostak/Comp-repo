#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll findMinCount(int arr[], int size, int num, int output[]){
	if(num==0){
		return 0;
	}
	if(num<0){
		return INT_MAX;
	}
	if(size==0){
		return INT_MAX;
	}

	int tosub=pow(arr[0],2);
	if(output[num]!=-1){
		return output[num];
	}
	ll first= findMinCount(arr,size,num-tosub,output);
	ll second=  findMinCount(arr+1,size-1,num,output);
	ll count= min(first+1,second);
	output[num]=count;
	//cout<<count<<" "<<num<<endl;
	return  count;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int req= sqrt(n);
		int arr[req];
		for(int i=0;i<req;i++){
			arr[i]=i+1;
		}

		int output[n+1];
		for(int i=0;i<=n;i++){
			output[i]=-1;
		}

		ll ans= findMinCount(arr,req,n,output);
		cout<<ans<<endl;

	}
}