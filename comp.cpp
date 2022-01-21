#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

bool visited[1000][1000];

bool validity(int x, int y, int n, int m){
    if(x>=0 && x<n && y>=0 && y<m){
        return true;
    }

    return false;
}

bool findingNinjas(char** charmatrix, int x, int y, int n,int m, string refer, int index){
    if(!visited[x][y]){
        visited[x][y]=1;
    }
    if(index==(refer.size()-1) && charmatrix[x][y]==refer[index]){
        return true;
    }


    if(validity(x-1,y,n,m) && charmatrix[x-1][y]==refer[index+1] && index<refer.size() && !visited[x-1][y]){
        bool check=findingNinjas(charmatrix,x-1,y,n,m,refer,index+1);
        if(check){
            return true;
        }
    }
    if(validity(x-1,y+1,n,m) && charmatrix[x-1][y+1]==refer[index+1] && index<refer.size() && !visited[x-1][y+1]){
        bool check=findingNinjas(charmatrix,x-1,y+1,n,m,refer,index+1);
        if(check){
            return true;
        }
    }
    if(validity(x,y+1,n,m) && charmatrix[x][y+1]==refer[index+1] && index<refer.size() && !visited[x][y+1]){
        bool check=findingNinjas(charmatrix,x,y+1,n,m,refer,index+1);
        if(check){
            return true;
        }
    }
    if(validity(x+1,y+1,n,m) && charmatrix[x+1][y+1]==refer[index+1] && index<refer.size() && !visited[x+1][y+1]){
        bool check=findingNinjas(charmatrix,x+1,y+1,n,m,refer,index+1);
        if(check){
            return true;
        }
    }
    if(validity(x+1,y,n,m) && charmatrix[x+1][y]==refer[index+1] && index<refer.size() && !visited[x+1][y]){
        bool check=findingNinjas(charmatrix,x+1,y,n,m,refer,index+1);
        if(check){
            return true;
        }
    }
    if(validity(x+1,y-1,n,m) && charmatrix[x+1][y-1]==refer[index+1] && index<refer.size() && !visited[x+1][y-1]){
        bool check=findingNinjas(charmatrix,x+1,y-1,n,m,refer,index+1);
        if(check){
            return true;
        }
    }
    if(validity(x,y-1,n,m) && charmatrix[x][y-1]==refer[index+1] && index<refer.size() && !visited[x][y-1]){
        bool check=findingNinjas(charmatrix,x,y-1,n,m,refer,index+1);
        if(check){
            return true;
        }
    }
    if(validity(x-1,y-1,n,m) && charmatrix[x-1][y-1]==refer[index+1] && index<refer.size() && !visited[x-1][y-1]){
        bool check=findingNinjas(charmatrix,x-1,y-1,n,m,refer,index+1);
        if(check){
            return true;
        }
    }

    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        char** charmatrix= new char*[n];
        for(int i=0;i<n;i++){
            charmatrix[i]= new char[m];
        }

        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                charmatrix[i][j]=s[j];
            }
        }

        string refer= "CODINGNINJA";
        bool ans=false;
        bool goOut=false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(charmatrix[i][j]==refer[0]){
                    ans= findingNinjas(charmatrix,i,j,n,m,refer,0);
                    if(ans){
                        cout<<"1"<<endl;
                        goOut=true;
                        break;
                    }
                    memset(visited,0,sizeof(visited));
                }
            }

            if(goOut){
                break;
            }
        }

        if(!ans){
            cout<<"0"<<endl;
        }

        for(int i=0;i<n;i++){
            delete [] charmatrix[i];
        }

        delete [] charmatrix;



    }
}