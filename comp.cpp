#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
#define test int t;cin>>t;while(t--)
#define limit 100000
using namespace std;

pair<int,int> isValid(vector<int> arr, int idx){
    int n=arr.size()-idx+1;

    for(int i=2;i<n;i++){
        for(int j=1;j<=i;j++){
            int a=0;
            int b=0;
            for(int k=idx;k<idx+j;k++){
                b=(10*b)+arr[k];
            }
            for(int k=idx+j;k<idx+i;k++){
                a=(10*a)+arr[k];
            }

            int c=0;
            for(int k=i+idx;k<arr.size();k++){
                c=(c*10)+arr[k];
                if(c==a+b){
                    cout<<c<<" "<<a<<" "<<b<<endl;
                    return {i+idx,j+idx};
                }
                if(c>a+b) break;
            }

        }
    }

    return {-1,-1};
}

bool findAddSeq(vector<int>& arr){
    int curIdx=0;
    int idx=0;
    while(idx<arr.size()-1){
        pair<int,int> p= isValid(arr,curIdx);
        //cout<<p.first<<" "<<p.second<<endl;
        if(p.first==-1) return false;
        idx= p.first;
        curIdx=p.second;
    }

    return true;
}

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

        vector<int> arr(s.size());

        for(int i=0;i<s.size();i++){
            arr[i]= s[i]-'0';
        }

        // auto p = isValid(arr, 1);

        // cout<<p.first<<" "<<p.second<<endl;

        cout<<findAddSeq(arr)<<endl;
    }



    return 0;
}