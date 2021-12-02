#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long


int main(){
	

	int n;
	cin>>n;
    int arr[n+1]={0};
	for(int i=2;i<n;i++){
		for(int j=2;j*i<=n;j++){
            if(arr[i]>=1){
                break;
            }
            else{
                arr[j*i]+=1;
            }
		}
	}
    
    int count=0;
	for(int i=3;i<=n;i++){
		if(arr[i]==2){
            count++;
        }
	}
    cout<<count<<endl;
    
    

	

}