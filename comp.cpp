#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        int count=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==0){
                count++;
            }
        }

        int i=0;
        int red=0;
        vector<int> arr1;
        arr1=arr;

        while(count && k>0){
            count=0;
            k--;
            for(int i=0;i<n;i++){
                if(i==0){
                    if(arr[i]>0){
                        arr1[n-1]++;
                        arr1[i+1]++;
                    }
                }
                if(i==n-1){
                    if(arr[i]>0){
                        arr1[0]++;
                        arr1[i-1]++;
                    }
                }

                if(arr[i]>0){
                    arr1[i-1]++;
                    arr1[i+1]++;
                }
            }

            arr=arr1;
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        ll k;
        cin>>n>>k;
        ll arr[n];
        int count=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==0){
                count++;
            }
        }
        
        if(count==n){
            cout<<"0"<<endl;
        }
        else{
        ll arr1[n];
        for(int i=0;i<n;i++){
            arr1[i]=arr[i];
        }

        while(count && k>0){
            count=0;
            k--;
            for(int i=0;i<n;i++){
                if(i==0){
                    if(arr[i]>0){
                        arr1[n-1]++;
                        arr1[1]++;
                    }
                }
                else if(i==n-1){
                    if(arr[i]>0){
                        arr1[0]++;
                        arr1[n-2]++;
                    }
                }

                else if(arr[i]>0){
                    arr1[i-1]++;
                    arr1[i+1]++;
                }
            }

            for(int i=0;i<n;i++){
                arr[i]=arr1[i];
                if(arr[i]==0){
                    count++;
                }
            }

        }
        
        ll sum=0;

        if(k>0){
            sum+=(2*k*n);
        }

        for(int i=0;i<n;i++){
            sum+=arr[i];
        }

        cout<<sum<<endl;
        }
    }
}
            for(int i=0;i<n;i++){
                if(arr[i]==0){
                    count++;
                }
            }
        }

        int sum=0;

        if(k>0){
            sum+=(k*n*2);
        }

        for(int i=0;i<n;i++){
            sum+=arr[i];
        }

        cout<<sum<<endl;
    }
}