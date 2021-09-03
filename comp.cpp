#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int x,y;
        cin>>x>>y;

        vector<int> eastarray;
        eastarray.push_back(0);
        int sum=0;
        for(int i=0;i<n;i++){
            if(s[i]=='N'){
                int cost= min(x,(3*y));
                sum+=cost;
                eastarray.push_back(sum);
            }
            else if(s[i]=='S'){
                int cost= min((3*x),y);
                sum+=cost;
                eastarray.push_back(sum);
            }
            else if(s[i]=='W'){
                int cost= min((2*x),(2*y));
                sum+=cost;
                eastarray.push_back(sum);
            }
            else if(s[i]=='E'){
                eastarray.push_back(sum);
            }
        }

        vector<int> westarray(n+1);
        westarray[n]=0;
        int wsum=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='N'){
                int cost= min((3*x),y);
                wsum+=cost;
                westarray[i]=wsum;
            }
            else if(s[i]=='S'){
                int cost= min(x,(3*y));
                wsum+=cost;
                westarray[i]=wsum;
            }
            else if(s[i]=='E'){
                int cost= min((2*x),(2*y));
                wsum+=cost;
                westarray[i]=wsum;
            }
            else if(s[i]=='W'){
                westarray[i]=wsum;
            }
        }

        vector<int> ans(n+1);
        for(int i=0;i<n+1;i++){
            ans[i]=eastarray[i]+westarray[i];
        }

        sort(ans.begin(),ans.end());

        cout<<ans[0]<<endl;

        
    }
}