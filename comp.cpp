#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
#define test int t;cin>>t;while(t--)
#define limit 100000
using namespace std;

int minStep(int step, int cur, int target, int count){
        if(cur==target) return count;

        if(cur>target) return -1;

        int c1= minStep(step+1,cur+step,target,count+1);
        if(c1!=-1) return c1;
        int c2= minStep(step+1,cur-step,target,count+1);
        if(c2!=-1) return c2;

        return -1;
}

int findTiles(int n, int m){
    if(n<=0 || m<=0) return 0;
    if(n==1 || m==1) return n*m;

    int tileSize= log2(min(n,m));
    tileSize= pow(2,tileSize);

    int ans=1;

    ans+= findTiles(n-tileSize, tileSize);
    ans+= findTiles(tileSize, m- tileSize);
    ans+= findTiles(n-tileSize, m-tileSize);

    return ans;

}

int findCandy(int candy, int wrap, int aWrap){

    int totalWrap= candy+aWrap;
    //cout<<totalWrap<<endl;

    if(totalWrap<=wrap) return 0;

    candy= (totalWrap)/wrap;
    aWrap= totalWrap%wrap;

    return candy+findCandy(candy,wrap,aWrap);

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    test{
        int target;
        cin>>target;

        cout<<minStep(1,0,target,0)<<endl;
    }

    return 0;
}