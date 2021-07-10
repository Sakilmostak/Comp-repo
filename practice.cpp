#include<bits/stdc++.h>

using namespace std;

bool isPowerOfTwo(int x)
    {
        return (x && !(x & (x - 1)));
    }

int lp(int n){
	n=n | (n>>1);
	n=n | (n>>2);
	n=n | (n>>4);
	n=n | (n>>8);

	return (n+1)>>1;
}

int main(){
	int n=3;
	int arr[] = {3,6,10};
	int m=2;
	int count=0;
	int xorp;

	do{
		xorp=0;
		int c;
		for(int i=0;i<n;i++){
			if(arr[i]>0){
				c= arr[i];
				break;
			}
		}
		int s;
		if(isPowerOfTwo(c)){
			s=c;
		}
		else{
			s= lp(c);
		}
		int k=m;
		count++;
		for(int i=0;i<n;i++){
			if(arr[i]>s && k>0){
				arr[i]^= s;
				k--;
			}
		}
		for(int i=0;i<n;i++){
			xorp^=arr[i];
		}
	}while(xorp!=0);

	cout<<count<<endl;

}