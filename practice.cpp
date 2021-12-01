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
    if(n==1){
        cout<<"0"<<endl;
        return 0;
    }
	int count=1;
	for(int i=3;i<=n;i++){
		if(arr[i]==0){
			count++;
		}
	}

	cout<<count<<endl;

}