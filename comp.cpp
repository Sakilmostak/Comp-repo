#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ff first
#define ss second

int main(){
    int n,k;
    cin>>n>>k;

    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int sum=0;
    int ans;

    for (int i=0;i<k;i++){
        sum+= a[i];
    }

    ans= sum;

    for(int i=1;i<n-k+1;i++){
        sum-= a[i-1];
        sum+= a[i+k-1];
        ans= min(ans, sum);
    }

    cout<<ans<<endl;

    return 0;
}