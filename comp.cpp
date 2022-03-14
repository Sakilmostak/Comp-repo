#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        bool arr[1000][1000]={0};
        for(int i=0;i<dig.size();i++){
            arr[dig[i][0]][dig[i][1]]=1;
        }
        
        int n1= artifacts.size();
        
        int count=0;
        
        for(int f=0;f<n1;f++){

            int x1= artifacts[f][0];
            int y1= artifacts[f][1];
            int x2= artifacts[f][2];
            int y2= artifacts[f][3];
            //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
            bool flag=true;
            for(int j=x1;j<=x2;j++){
                for(int k=y1;k<=y2;k++){
                    if(!arr[j][k]){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                count++;
            }
        }
        return count;
        
    }
};