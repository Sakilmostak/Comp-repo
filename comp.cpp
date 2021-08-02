#include<bits/stdc++.h>
#define ll int long long

using namespace std;

int main(){
    int n,d;
    cin>>n >>d;
    vector<int> ar(n);
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    sort(ar.begin(), ar.end());

    int i=0, count=0;

    while(i<n-1){
        if(abs(ar[i]-ar[i+1])<=d){
            count++;
            i+=2;
        }
        else{
            i++;
        }
    }

    cout<<count<<endl;
}