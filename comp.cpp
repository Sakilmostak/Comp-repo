#include<bits/stdc++.h>
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
    }int ans=1;
    for(int i=0;i<n;i++){
        ans=max(ans,max(2*v[i]-1,2*v1[i]));
    }return ans;
}
int main(){
	string s;cin>>s;
    cout<<helper(s,s.size())<<endl;
    return 0;
}