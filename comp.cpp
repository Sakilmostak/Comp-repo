#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define MAX 100001

int modExp(int a, int b, int c){
	if(a==0){
		return 0;
	}
	if(b==0){
		return 1;
	}

	long ans;
	if(b%2==0){
		long smallAns= modExp(a,b/2,c);
		ans= (smallAns*smallAns)%c;
	}
	else{
		long smallAns= modExp(a,b-1,c);
		ans= (a%c);
		ans= (ans*smallAns)%c;
	}

	return int((ans+c)%c);
}

int main(){
	int a,b,c;
	cin>>a>>b>>c;

	cout<<modExp(a,b,c)<<endl;

	return 0;
}