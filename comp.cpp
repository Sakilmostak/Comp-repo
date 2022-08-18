#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
#define test int t;cin>>t;while(t--)
#define limit 100000
using namespace std;


int euclidGCD(int a,int b){
    if(b==0) return a;

    return euclidGCD(b, a%b);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    

    
    test{

        int a,b;
        cin>>a>>b;

        int gcd= euclidGCD(a,b);

        int toDiv= a/gcd;

        if(b%toDiv==0){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
        
        
        

    }

    return 0;
}