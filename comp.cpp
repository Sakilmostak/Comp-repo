#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a0=0,a1=0,b0=0,b1=0;
        for(int i=0;i<3;i++){
            int x;
            cin>>x;
            if(x==0){
                a0++;
            }
            else{
                a1++;
            }
        }
        for(int i=0;i<3;i++){
            int x;
            cin>>x;
            if(x==0){
                b0++;
            }
            else{
                b1++;
            }
        }

        if(a0==b0 && a1==b1){
            cout<<"Pass"<<endl;
        }
        else{
            cout<<"Fail"<<endl;
        }
    }
}