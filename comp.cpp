#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%4==1){
            cout<<n-1<<endl;
        }
        else{
            cout<<n<<endl;
        }
    }
}