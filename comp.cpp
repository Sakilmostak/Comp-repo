#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
#define test int t;cin>>t;while(t--)
#define limit 100000
using namespace std;




int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    test{
        string s;
        cin>>s;
        vector<bool> arr(limit+1,0);
        arr[1]=1;
        for(int i=2;i<=sqrt(limit);i++){
            if(!arr[i]){
                
                for(int j=2*i;j<=limit;j+=i){
                    arr[j]=1;
                }
            }
        }

        // for(int i=0;i<99;i++){
        //     if(!arr[i]) cout<<i<<endl;
        // }

        vector<int> freq(26,0);

        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }

        bool check= true;
        int count=0;

        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                count++;
                if(arr[freq[i]]) check=false;
            }
        }

        if(arr[count]) check=false;

        if(check){
            cout<<" The given string is prime"<<endl;
        }
        else{
            cout<<" The given string is not prime"<<endl;
        }

        
    }

    return 0;
}