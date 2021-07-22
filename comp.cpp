#include<bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        string ch=s.substr(0,3);
        bool see=true;
        
        if(ch=="101" || ch=="010"){
            cout<<"Good"<<endl;
            see=false;
        }
        else{
            for(int i=3;i<s.size();i++){
                
                ch.push_back(s[i]);
                ch.erase(ch.begin());
                if(ch=="101" || ch=="010"){
                    cout<<"Good"<<endl;
                    see=false;
                    break;
                }
            }
            
        }
        
        if(see){
            cout<<"Bad"<<endl;
        }
        

        
    }
}