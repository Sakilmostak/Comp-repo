#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;


void buildZ(int* Z, string str){
	int l=0,r=0;

	int n= str.length();
	for(int i=1;i<n;i++){

		if(i>r){
			//i does not lie between l and r
			// Z for this does not exist
			l=i;
			r=i;
			while(r<n && str[r-l]==str[r]){
				r++;
			}

			Z[i]=r-l;
			r--;
		}
		else{
			int k= i-l;
			if(Z[k]<=r-i){
				// i lies between l and r
				// Z will exist previously
				Z[i]=Z[k];
			}
			else{
				// Some part of Z is already included
				// You have to start matching further
				l=i;
				while(r<n && str[r-l]==str[r]){
					r++;
				}
				Z[i]=r-l;
				r--;
			}
		}
	}
}

void searchString(string text,string pattern){
	string str= pattern+ "$" +text;
	int n= str.length();
	int* Z= new int[n]();
	buildZ(Z,str);
	for(int i=0;i<n;i++){
		if(Z[i]==pattern.length()){
			cout<<"Patter found at index : "<<i-pattern.length()-1<<endl;
		}
	}
}

int main(){
	string text,pattern;
	cin>>text;
	cin>>pattern;
	searchString(text,pattern);
}