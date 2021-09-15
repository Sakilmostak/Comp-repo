#include<bits/stdc++.h>

using namespace std;

int partition(int arr[],int size){
    int comp= arr[0];
    int count=0;
    for(int i=1;i<size;i++){
        if(arr[i]<comp){
            count++;
        }
    }

    if(count!=0){
        swap(arr[0],arr[count]);
    }

    int i=0;
    int j= size-1;

    while(i<count && j>count){
        int ind1=i;
        while(arr[ind1]<comp){
            ind1++;
        }
        i=ind1;
        int ind2=j;
        while(arr[ind2]>=comp){
            ind2--;
        }
        j=ind2;

        if(arr[ind1]>comp && arr[ind2]<comp)
        swap(arr[ind1],arr[ind2]);
    }

    return count;
}

void quickSort(int arr[], int size){
    if(size<=1){
        return;
    }

    int comp= arr[0];
    int count=0;
    for(int i=1;i<size;i++){
        if(arr[i]<comp){
            count++;
        }
    }

    if(count!=0){
        swap(arr[0],arr[count]);
    }

    int i=0;
    int j= size-1;

    while(i<count && j>count){
        int ind1=i;
        while(arr[ind1]<comp){
            ind1++;
        }
        i=ind1;
        int ind2=j;
        while(arr[ind2]>=comp){
            ind2--;
        }
        j=ind2;

        if(arr[ind1]>comp && arr[ind2]<comp)
        swap(arr[ind1],arr[ind2]);
    }

    quickSort(arr,count);
    quickSort(arr+count+1,size-count-1);

}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    quickSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}