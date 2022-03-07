#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

string convert(string s, int numRows) {
        if(numRows<=1){
            return s;
        }
        string numstr[numRows];
        for(int i=0;i<numRows;i++){
            numstr[i]="";
        }
        int flag=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(flag==0){
                numstr[j]+=s[i];
                j++;
                if(j>numRows-1){
                    flag=1;
                    j=numRows-2;
                }
            }
            else if(flag==1){
                numstr[j]+=s[i];
                j--;
                if(j<0){
                    flag=0;
                    j=1;
                }
            }
        }
        
        string ans="";
        for(int i=0;i<numRows;i++){
            ans+=numstr[i];
        }
        
        return ans;
    }


int main(){
	string s;cin>>s;
	int n;cin>>n;
    cout<<convert(s,n)<<endl;
    return 0;
}