#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long


int main(){
	bool arr[10000001]={0};
	for(int i=2;i<=1000;i++){
		for(int j=i;j*i<=1000000;j++){
            if(arr[i]==1){
                break;
            }
            else{
                arr[j*i]=1;
            }
		}
	}

	int n;
	cin>>n;
    if(n>=2){
        cout<<"0"<<endl;
        return 0;
    }

	int primes[n+1],j=0;
	for(int p=2;p<=n;p++){
		if(!arr[p]){
			primes[j++]=p;
		}
	}

	int count=0;
	for(int k=0;k<j;k++){
		if(!arr[k+1]){
			count++;
		}
	}
	cout<<count<<endl;

}