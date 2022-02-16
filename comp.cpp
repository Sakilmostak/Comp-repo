#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,x,y;
		cin>>n>>x>>y;
		ll emi=0LL;
		if(n<=4){
			if(y<=x){
				emi=y;
			}
			else{
				emi=x;
			}
		}
		else if(n>4 && n<=100){
			int i=n/4;
			if(n%4!=0){
				i++;
			}
			
			if(i*y<x){
				emi=i*y;
			}
			else{
				emi=x;
			}
		}
		else if(n>100){
			if(y*25<=x){
				int i=n/4;
				if(n%4!=0){
					i++;
				}
				emi=i*y;
			}
			else{
				emi=x*(n/100);
				int i=(n%100)/4;
				if(n%4!=0){
					i++;
				}

				if(i*y<x){
					emi+= (i*y);
				}
				else{
					emi+=x;
				}
			}
		}

		cout<<emi<<endl;
	}
}