#include<bits/stdc++.h>
using namespace std;

void placeNQueen(int arr[][10],int n, int para){
    if(para==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;

        return;
    }

    for(int i=0;i<n;i++){
        bool check= true;
        int j=para,k=i;
        while(j>=0){
            if(arr[j][i]==1){
                check=false;
                break;
            }
            j--;
        }
        j=para;
        while(j>=0 && k>=0){
            if(arr[j][k]==1){
                check=false;
                break;
            }
            j--;
            k--;
        }
        j=para;
        k=i;
        while(j>=0 && k<n){
            if(arr[j][k]==1){
                check=false;
                break;
            }
            j--;
            k++;
        }
        if(check){
            arr[para][i]=1;
            placeNQueen(arr,n,para+1);
            arr[para][i]=0;
        }
        
    }

}

int main(){
    int n;
    cin>>n;
    int arr[10][10]={0};
    placeNQueen(arr, n, 0);
}