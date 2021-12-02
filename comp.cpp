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
    int primes[n+1],j=0;
    for(int i=2;i<=n;i++){
        if(arr[i]==0){
            primes[j++]=i;
        }
    }
    
    int count=0;
    
    for(int i=0;i<j-1;i++){
        int sprime=primes[i]+primes[i+1]+1;
        if(arr[sprime]==0 && sprime<=n){
            arr[sprime]=1;
            count++;
        }
    }
    
    cout<<count<<endl;

}