#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

void buildtree(ll arr[], ll *oddtree, ll* eventree, int start, int end, int treeidx){
    if(start==end){
        if(arr[start]&1 == 1){
            oddtree[treeidx]=1;
            eventree[treeidx]=0;
            return;
        }
        else{
            oddtree[treeidx]=0;
            eventree[treeidx]=1;
            return;
        }
    }

    int mid = (start+end)/2;
    buildtree(arr,oddtree,eventree,start,mid,2*treeidx);
    buildtree(arr,oddtree,eventree,mid+1,end,2*treeidx+1);

    oddtree[treeidx]=oddtree[2*treeidx]+oddtree[2*treeidx+1];
    eventree[treeidx]=eventree[2*treeidx]+eventree[2*treeidx+1];


}

void updateTree(ll arr[], ll* oddtree, ll* eventree, int start, int end, int treeidx, int idx, int value){
    if(start==end){
        arr[start]=value;
        if(value&1==1){
            oddtree[treeidx]=1;
            eventree[treeidx]=0;
        }
        else{
            oddtree[treeidx]=0;
            eventree[treeidx]=1;
        }

        return;
    }

    int mid= (start+end)/2;
    if(mid<idx){
        updateTree(arr,oddtree,eventree,mid+1,end,2*treeidx+1,idx,value);
    }
    else{
        updateTree(arr,oddtree,eventree,start,mid,2*treeidx,idx,value);
    }
    oddtree[treeidx]=oddtree[2*treeidx]+oddtree[2*treeidx+1];
    eventree[treeidx]= eventree[2*treeidx]+eventree[2*treeidx+1];
}

int queryEven(ll arr[], ll* eventree, int start, int end, int treeidx, int left, int right){
    if(right< start || left> end){
        return 0;
    }

    if(left<=start && right>=end){
        return eventree[treeidx];
    }

    int mid = (start+end)/2;
    int ans1 = queryEven(arr,eventree,start,mid,2*treeidx,left,right);
    int ans2 = queryEven(arr,eventree,mid+1,end,2*treeidx+1,left,right);
    return ans1+ans2;
}

int queryOdd(ll arr[], ll* oddtree, int start, int end, int treeidx, int left, int right){
    if(right< start || left> end){
        return 0;
    }

    if(left<=start && right>=end){
        return oddtree[treeidx];
    }

    int mid = (start+end)/2;
    int ans1 = queryOdd(arr,oddtree,start,mid,2*treeidx,left,right);
    int ans2 = queryOdd(arr,oddtree,mid+1,end,2*treeidx+1,left,right);
    return ans1+ans2;
}

int main(){
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll *oddtree= new ll[4*n];
    ll *eventree= new ll[4*n];
    buildtree(arr,oddtree,eventree,0,n-1,1);

    int q;
    cin>>q;
    while(q--){
        ll check,x,y;
        cin>>check>>x>>y;
        if(check==0){
            updateTree(arr,oddtree,eventree,0,n-1,1,x-1,y);
        }
        else if(check==1){
            int ans=queryEven(arr,eventree,0,n-1,1,x-1,y-1);
            cout<<ans<<endl;
        }
        else if(check==2){
            int ans=queryOdd(arr,oddtree,0,n-1,1,x-1,y-1);
            cout<<ans<<endl;
        }
    }

    


}