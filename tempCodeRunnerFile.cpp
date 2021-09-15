#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n][n]={0};

        int *i,*j;
        *i=0;
        *j=0;

        while(*i<n){
            bool check=true;
            while(*j<n){
                if(arr[*i][*j]!=-1){
                    arr[*i][*j]=1;
                }
                *j++;
                if(*i>=1 || *j>=1){
                    int sum=0,pro=1;
                    for(int k=0;k<*j;k++){
                        sum+=arr[*i][k];
                        pro*=arr[*i][k];
                    }

                    int csum=0,cpro=1;
                    for(int l=0;l<=*i;l++){
                        csum+=arr[l][*j];
                        cpro*=arr[l][*j];
                    }

                    if((sum*pro)>=0){
                        *j--;
                        if(arr[*i][*j]==1){
                            arr[*i][*j]=-1;
                        }
                        else if (arr[*i][*j]==-1){
                            arr[*i][*j]=1;
                        }
                    }
                    else if((csum*cpro)>=0){
                        if(arr[*i][*j]==1){
                            arr[*i][*j]=-1;
                        }
                        else if (arr[*i][*j]==-1){
                            arr[*i][*j]=1;
                        }

                        *i--;
                        check=false;
                        break;
                    }
                }
            }
            if(check){
                i++;
            }
        }

        for(int f=0;f<n;f++){
            for(int d=0;d<n;d++){
                cout<<arr[f][d]<<" ";
            }
            cout<<endl;
        }
    }
}