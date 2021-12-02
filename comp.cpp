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
	int count=0;
	for(int i=2;i<=n+1;i++){
		if(arr[i]==0){
			count++;
		}
	}
    
    if(n==1){
        cout<<"1"<<endl;
        cout<<"0"<<" "<<"1"<<endl;
    }
    else if(n<=7){
        cout<<"2"<<endl;
        cout<<n-count<<" "<<count<<endl;
    }
    else{
        cout<<"2"<<endl;
        cout<<count<<" "<<n-count<<endl;
    }
}