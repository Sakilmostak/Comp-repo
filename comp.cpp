#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        map<int,int> m;
        for(int i=0;i<4;i++){
            int x;
            cin>>x;
            m[x]++;
        }

        map<int,int> :: iterator it;
        int count=0;

        for(it=m.begin();it!=m.end();it++){
            count++;
        }
        if(count==1){
            cout<<"0"<<endl;
        }
        else if(count==2){
            if(m.begin()->second==2){
                cout<<"2"<<endl;
            }
            else{
                cout<<"1"<<endl;
            }
        }
        else if(count==3 || count==4){
            cout<<"2"<<endl;
        }

    }
}