#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long


int main(){
	ll arr[1000001]={0};
	for(int i=2;i<1000000;i++){
		for(int j=2;j*i<=1000000;j++){
            if(arr[i]>=1){
                break;
            }
            else{
                arr[j*i]+=1;
            }
		}
	}
    
    int t;
    cin>>t;
    while(t--){
        ll a,b,n;
        cin>>a>>b>>n;
        
        int count=0;
        int primecount=0;
        
        for(int i=a;i<=b;i++){
            if(arr[i]==n){
                count++;
            }
            if(arr[i]==0 && i>=2){
                primecount++;
            }
        }
        
        if(n==1){
            cout<<count+primecount<<endl;
        }
        else{
            cout<<count<<endl;
        }
    }
    

	

}