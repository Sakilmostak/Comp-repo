#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int LPS(string s){
	string newstr;
	newstr+="$";
	for(int i=0;i<s.size();i++){
		newstr=newstr+"#"+s[i];
	}
	newstr+="#@";
	
	//Manacher's Algorithm
	int n= newstr.size();
	int *P= new int[n]();    // initialize to zero
	int center=0,right=0;

	for(int i=1;i<n-1;i++){
		int mirror=(2*center) - i;
		
		if(i<right){
			P[i]=min(right-i,P[mirror]);
		}

		while((i+1+P[i])<n && (i-1-P[i])>=0 && newstr[i+1+P[i]]==newstr[i-1-P[i]]){
			P[i]++;
		}

		if(i+P[i]>right){
			center=i;
			right=i+P[i];
		}
	}

	// finding longest palindrome
	int ans=1;
	for(int i=0;i<n;i++){
		ans=max(ans,P[i]);
	}

	delete[] P;

	return ans;

}

int main(){
	string s;
	cin>>s;
	int ans=LPS(s);
	cout<<ans<<endl;
}