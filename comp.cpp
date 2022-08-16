#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
#define test int t;cin>>t;while(t--)
using namespace std;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    test{
        int n;
        cin>>n;
        vector<bool> arr(n+1,0);
        for(int i=2;i<=sqrt(n);i++){
            if(!arr[i]){
                
                for(int j=2*i;j<=n;j+=i){
                    arr[j]=1;
                }
            }
        }

        unordered_map<int,int> mp;

        for(int i=2;i<=n;i++){
            if(!arr[i]){
                int num=i;
                while(num){
                    int digit = num%10;
                    mp[digit]++;
                    num/=10;
                }
            }
        }

        int ans=-1;
        int maxy=INT_MIN;

        for(auto it: mp){
            if(it.second>maxy){
                maxy=it.second;
                ans=it.first;
            }
        }

        cout<<"Highest occuring digit is "<<ans<<" with count "<<maxy<<" times"<<endl;
    }

    return 0;
}