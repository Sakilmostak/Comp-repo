#include<bits/stdc++.h>

using namespace std;

void checkTriplet(int a, int b,int c,int n, int* count){
	if(a==0){
		checkTriplet(n,b-1,c,n,count);
		return;
	}
	if(b==1){
		return;
	}

	if(b%c==0){
		if(a%b==c){
			*count+=1;
		}
	}

	checkTriplet(a-1,b,c,n,count);

	return;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
	cin>>n;
	int count=0;
	for(int c=1;c<=n/2;c++){
		checkTriplet(n,n,c,n,&count);
	}

	cout<<count<<endl;
	}
	
	return 0;
}
	