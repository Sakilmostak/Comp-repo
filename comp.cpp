#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll decodealpha(string s, int size){
	ll* output= new ll[size+1];
	output[0]=1;
	output[1]=1;
	

	for(int i=2;i<=size;i++){
        if(s[i-1]=='0'){
            return 0;
        }
		output[i]=output[i-1]%mod;
		int fa=s[i-2]-'0';
        int fb=s[i-1]-'0';
        int check= fa*10 + fb;
		if(check<=26){
			output[i]+=output[i-2]%mod;
		}
	}

	ll myans=output[size]%mod;
	delete [] output;
	return myans;
}

int main(){
	int t;cin>>t;
	while(t--){
		string s;
		cin>>s;

		ll ans= decodealpha(s,s.size());
		cout<<ans<<endl;
		
	}
}