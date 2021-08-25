#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<char> sCap;
    for(int i=0;i<s.length();i++){
        sCap.push_back(s[i]-32);
    }
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string Balpha= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while(n--){
        string take;
        cin>>take;
        vector<char> ans;
        for(int i=0;i<take.length();i++){
            if(take[i]=='_'){
                ans.push_back(' ');
            }
            else if(take[i]>='a' && take[i]<='z'){
                for(int j=0;j<alpha.length();j++){
                    if(take[i]==alpha[j]){
                        ans.push_back(s[j]);
                        break;
                    }
                }
            }
            else if(take[i]>='A' && take[i]<='Z'){
                for(int j=0;j<Balpha.length();j++){
                    if(take[i]==Balpha[j]){
                        ans.push_back(sCap[j]);
                        break;
                    }
                }
            }
            else{
                ans.push_back(take[i]);
            }
        }

        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
        }
        cout<<endl;
    }
}