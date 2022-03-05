#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

class check{
    public:
    int data, lastval;
};

int multiples[100001];

int deleteAndEarn(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            multiples[nums[i]]++;
        }
        int dp[10001]={0};
        dp[0]=0;
        dp[1]=multiples[1]*1;
        dp[2]=multiples[2]*2;
        for(int i=3;i<=10000;i++){
            dp[i]=multiples[i]*i;
            dp[i]+=max(dp[i-2],dp[i-3]);
        }
        
        return dp[10000];
        
    }
int main(){
    
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<deleteAndEarn(v);
}