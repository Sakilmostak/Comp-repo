#include<bits/stdc++.h>

using namespace std;

int pairSum(int *arr,int n){
    sort(arr,arr+n);

    int start=0;
    int end=n-1;
    int a=0,b=0;
    int count=0;
    while(start<end){
        if((arr[start]+arr[end])==0){
            int para1= arr[start];
            int para2= arr[end];
            while(arr[start]==para1 && start<n){
                a++;
                start++;
            }
            while(arr[end]==para2 && end>0){
                b++;
                end--;
            }
            if(para1==0){
                count=count + ((a*(a-1))/2);
            }
            else if(para2==0){
                count= count+ ((b*(b-1))/2);
            }
            else{
                count= count + (a*b);
            }
            a=0;
            b=0;
        }
        while((arr[start]+arr[end])>0){
            end--;
        }
        while((arr[start]+arr[end])<0){
            start++;
        }
    }

    return count;
}



int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}