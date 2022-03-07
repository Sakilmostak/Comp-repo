#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int helper(string s,int n){
    vector<int> v(n);
    for(int i=0,l=0,r=-1;i<n;i++){
        int k=(i>r)?1:min(v[l+r-i],r-i+1);
        while(0<=i-k and i+k<n and s[i-k]==s[i+k])
            k++;
        v[i]=k--;
        if(i+k>r){
            l=i-k;r=i+k;
        }
    }vector<int> v1(n);
        for(int i=0,l=0,r=-1;i<n;i++){
        int k=(i>r)?0:min(v1[l+r-i+1],r-i+1);
        while(0<=i-k-1 and i+k<n and s[i-k-1]==s[i+k])
            k++;
        v1[i]=k--;
            if(i+k>r){
                l=i-k-1;
                r=i+k;
            }
    }
	
	int ans=1;
	int index=0;
	int flag=0;  // 0 for odd and 1 for even
	
    for(int i=0;i<n;i++){
		if(2*v[i]-1>2*v1[i]){
			if(2*v[i]-1>ans){
				ans=2*v[i]-1;
				index=i;
				flag=0;
			}
		}
		else{
			if(2*v1[i]>ans){
				ans=2*v1[i];
				index=i;
				flag=1;
			}
		}
    }

	if(flag==0){
		int sidx= index-(ans/2);
		int eidx= index+ (ans/2);
		for(int i=sidx;i<=eidx;i++){
			cout<<s[i];
		}
		cout<<endl;
	}
	else if(flag==1){
		int sidx= (index)-(ans/2);
		int eidx= index+(ans/2)-1;
		for(int i=sidx;i<=eidx;i++){
			cout<<s[i];
		}
		cout<<endl;
	}
}
int main(){
	string s;cin>>s;
    helper(s,s.size());
    return 0;
}