#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int myAtoi(string s) {
        while(s[0]==' '){
            s=s.substr(1);
        }
        long sign=1;
        if(s[0]=='+'){
            sign=1;
        }
        else if(s[0]=='-'){
            sign=-1;
        }
        
        if(s[0]=='+' || s[0]=='-'){
            s=s.substr(1);
        }
        
        long ans=0L;
        
        for(const char c: s)
        {
            if(c>='0' && c<='9'){
                int digit= c-'0';
                ans=(10*ans)+digit;
                
                if(sign*ans<INT_MIN){
                    return INT_MIN;
                }
                if(sign*ans>INT_MAX){
                    return INT_MAX;
                }
            }
            else{
                return sign*ans;
            }
        } 
        
        return sign*ans;
    }


int main(){
	cout<<myAtoi("-927419734927298292834");
}