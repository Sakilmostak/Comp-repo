#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

double champagneTower(int poured, int query_row, int query_glass) {
        float dp[100][100]={0};
        dp[0][0]=poured/1.0;
        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){
                if(dp[i][j]>1){
                    dp[i+1][j]+=(dp[i][j]-1)/2;
                    dp[i+1][j+1]+=(dp[i][j]-1)/2;
                    dp[i][j]=1.0;
                }
            }
        }
        
        return dp[query_row][query_glass];
        
    }


int main(){
    cout<<champagneTower(6,3,2);
}