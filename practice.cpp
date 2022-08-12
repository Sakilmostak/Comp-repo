#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
using namespace std;


int main()
{
    string line;
    vector<string> v;
    map<char,int> mp;
 
    while (getline(cin, line))
    {
        if (line.empty()) {
            break;
        }
        v.push_back(line);
    }
     
    for(string i:v){
        for(char c:i){
            mp[c]++;
        }
    }
    
    string str= "covid";
    int ans=INT_MAX;
    for(char i: str){
        ans=min(ans,mp[i]);
    }
    
    cout<<ans<<endl;
 
    return 0;
}
