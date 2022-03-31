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

        int op=0;
        int fidx=0;
        vector<pair<int,int>> v;
        bool arr[n];

        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                arr[i]=0;
            }
            else{
                arr[i]=1;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                fidx=i;
                break;
            }
        }

        for(int i=fidx;i>=0;i--){
            if(arr[i]==1){
                op++;
                v.push_back({1,i+1});
                for(int j=0;j<=i;j++){
                    arr[j]= !arr[j];
                }
            }
        }

        cout<<op<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        

    }
}