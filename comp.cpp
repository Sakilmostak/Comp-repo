#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

struct job{
    public:

    int start;
    int finish;
    int profit;

};

bool comp(struct job f, struct job s){
    if(f.finish==s.finish){
        return f.start<s.start;
    }
    return f.finish<s.finish;
}

int binarySearch(struct job arr[],int i){
    int st=0,ed=i-1;
    while(st<=ed){
        int mid= (st+ed)/2;
        if(arr[mid].finish<=arr[i].start){
            if(arr[mid+1].finish<=arr[i].start){
                st=mid+1;
            }
            else{
                return mid;
            }
        }
        else{
            ed= mid-1;
        }

    }

    return -1;
}

int main(){
    int n;
    cin>>n;
    struct job arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
    }

    sort(arr,arr+n,comp);

    /*for(int i=0;i<n;i++){
        cout<<arr[i].start<<" "<<arr[i].finish<<" "<<arr[i].profit<<endl;
    }*/

    ll dp[n]={0};
    dp[0]=arr[0].profit;

    for(int i=1;i<n;i++){
            ll incprof=arr[i].profit;
            int toinc= binarySearch(arr,i);
            if(toinc!=-1){
                incprof+=dp[toinc];
            }

            dp[i]=max(incprof,dp[i-1]);
    }

    cout<<dp[n-1]<<endl;


}