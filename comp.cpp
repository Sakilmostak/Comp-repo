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
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        ll ans=1;
        
        for(int i=2;i<=n;i++){
            if(arr[i]==0){
                int divcount=0;
                int k=i;
                while(k<=n){
                    divcount+= (n/k)%mod;
                    k*=i;
                }
                
                ans= ((ans%mod)*((divcount+1)%mod))%mod;
            }
        }
        
        cout<<ans<<endl;
    }

}