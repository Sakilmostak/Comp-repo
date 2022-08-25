#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
#define test int t;cin>>t;while(t--)
#define limit 100000
using namespace std;

void bubbleSort(vector<int>& arr){
    int count=0;

    for(int i=1;i<arr.size();i++){
        if(arr[i-1]>arr[i]){
            count++;
            swap(arr[i-1],arr[i]);
        }
    }

    if(count==0) return;

    bubbleSort(arr);
}

void insertionSort(vector<int>& arr,int idx){
    if(idx==arr.size()) return;

    int i=idx;
    while(arr[i]<arr[i-1]){
        swap(arr[i],arr[i-1]);
        i--;
    }

    insertionSort(arr,idx+1);
}

void selectionSort(vector<int>& arr,int idx){
    if(idx==arr.size()) return;

    int miny=idx;
    for(int i=idx;i<arr.size();i++){
        miny = arr[i]<arr[miny]? i : miny;
    }

    swap(arr[idx],arr[miny]);

    selectionSort(arr,idx+1);
}

void DtoB(int n){
    if(n==0) return;

    DtoB(n/2);

    cout<<n%2;
}



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    selectionSort(arr,0);
    cout<<"Selection Sort: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    insertionSort(arr,0);
    cout<<"Insertion Sort: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    bubbleSort(arr);
    cout<<"Bubble Sort: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // test{
    //     int n;
    //     cin>>n;

    //     DtoB(n);
    //     cout<<endl;
    // }

    return 0;
}