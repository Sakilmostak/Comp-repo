#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

struct city{
	double x,y,f;
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		city cities[n];
		for(int i=0;i<n;i++){
			cin>>cities[i].x;
			cin>>cities[i].y;
			cin>>cities[i].f;
		}

		double dp[n];
		for(int i=0;i<n;i++){
			dp[i]=(-1*INT_MAX);
		}

		dp[0]=cities[0].f;

		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				dp[i]=max(dp[i],dp[j]+cities[i].f-(sqrt(pow(cities[i].x-cities[j].x,2)+pow(cities[i].y-cities[j].y,2))));
				
			}
			//cout<<dp[i]<<endl;
		}
		cout<<fixed;
		cout<<setprecision(6)<<dp[n-1]<<endl;

	}
}