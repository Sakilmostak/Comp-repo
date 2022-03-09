#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count=0;
        for(int i=0;i<n;){
            if(s[i]==s[i+1] && i!=n-1){
                count++;
                i+=2;
            }
            else{
                count++;
                i++;
            }
        }

        cout<<count<<endl;
    }
}