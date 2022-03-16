#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

bool valid(int x, int y, int n, int m){
    if(x>0 && x<=n && y>0 && y<=m){
        return true;
    }

    return false;
}

void findmincolor(int** arr, int n, int m, int x, int y){
    if(!valid(x,y,n,m)){
        return;
    }
    
    bool col[6]={0};
    if(valid(x,y+1,n,m)){
        col[arr[x][y+1]]=1;
    }
    if(valid(x,y-1,n,m)){
        col[arr[x][y-1]]=1;
    }
    if(valid(x+1,y,n,m)){
        col[arr[x+1][y]]=1;
    }
    if(valid(x-1,y,n,m)){
        col[arr[x-1][y]]=1;
    }

    for(int i=1;i<6;i++){
        if(!col[i]){
            arr[x][y]=i;
            break;
        }
    }


    if(valid(x,y+1,n,m) && arr[x][y+1]==0){
        findmincolor(arr,n,m,x,y+1);
    }
    if(valid(x,y-1,n,m) && arr[x][y-1]==0){
        findmincolor(arr,n,m,x,y-1);
    }
    if(valid(x+1,y,n,m) && arr[x+1][y]==0){
        findmincolor(arr,n,m,x+1,y);
    }
    if(valid(x-1,y,n,m) && arr[x-1][y]==0){
        findmincolor(arr,n,m,x-1,y);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int** arr= new int*[n+1];
        for(int i=0;i<=n;i++){
            arr[i]= new int[m+1];
            for(int j=0;j<=m;j++){
                arr[i][j]=0;
            }
        }

        //arr[x1][y1]=1;
        arr[x2][y2]=2;

        findmincolor(arr,n,m,x1,y1);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }


    }
}