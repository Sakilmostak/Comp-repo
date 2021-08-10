#include<bits/stdc++.h>

using namespace std;

void checkTriplet(int a, int b,int c,int n, int* count){
	if(a>n){
		checkTriplet(1,b+c,c,n,count);
		return;
	}
	if(b>n){
		return;
	}

	if(b%c==0){
		if(a%b==c){
			*count+=1;
		}
	}

	checkTriplet(a+1,b,c,n,count);

	return;
}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
	int t;
	cin>>t;
	while(t--){
		int n;
	cin>>n;
	int count=0;
	for(int c=1;c<=n/2;c++){
		checkTriplet(1,c,c,n,&count);
	}

	cout<<count<<endl;
	}
	
	return 0;
}
	