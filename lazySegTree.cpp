#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
#define test int t;cin>>t;while(t--)
#define limit 100000
using namespace std;

// create the segtree
// Time Comp: O(n)
void buildSegTree(vector<int>& segTreeMin, vector<int>& arr,int idx, int start, int end){
    if(start>end) return;
    if(start==end){
        segTreeMin[idx]=arr[start];
        return;
    }

    int mid= start+ (end-start)/2;

    buildSegTree(segTreeMin,arr,2*idx+1,start,mid);
    buildSegTree(segTreeMin,arr,2*idx+2,mid+1,end);

    segTreeMin[idx]= min(segTreeMin[2*idx+1],segTreeMin[2*idx+2]);

}

// update the range till the complete overlap
// Time comp: O(log(n))
// l=range left, r=range right, increment= value to be increased by
void updateRangeLazy(vector<int>& segTreeMin, vector<int>& lazy, int idx, int start, int end, int l, int r, int increment){
    //propagate the lazy value to child
    if(lazy[idx]!=0){
        segTreeMin[idx]+= lazy[idx];
        if(start!=end){
            lazy[2*idx+1]+= lazy[idx];
            lazy[2*idx+2]+= lazy[idx];
        }
        lazy[idx]= 0;
    }

    if(start>r || end<l) return; // if range doesn't overlap

    // if the range overlap completely
    // propagate the increment to the child 
    if(start>=l && end<=r){
        segTreeMin[idx]+=increment;

        if(start!=end){
            lazy[2*idx+1]+=increment;
            lazy[2*idx+2]+=increment;
        }

        return;
    }

    //partial overlap
    int mid = start+(end-start)/2;

    updateRangeLazy(segTreeMin,lazy,2*idx+1,start,mid,l,r,increment);
    updateRangeLazy(segTreeMin,lazy,2*idx+2,mid+1,end,l,r,increment);

    segTreeMin[idx] = min(segTreeMin[2*idx+1],segTreeMin[2*idx+2]);

}


// query for the range and propagate lazy value along it
// Time Comp: O(log(n))
int queryLazyMin(vector<int>& segTreeMin, vector<int>& lazy, int idx, int start, int end, int l, int r){
    //propagate the lazy value to child
    if(lazy[idx]!=0){
        segTreeMin[idx]+= lazy[idx];
        if(start!=end){
            lazy[2*idx+1]+= lazy[idx];
            lazy[2*idx+2]+= lazy[idx];
        }
        lazy[idx]= 0;
    }

    // if no overlap
    if(start>r || end<l) return INT_MAX;

    // if complete overlap
    if(start>=l && end<=r) return segTreeMin[idx];

    // if partial overlap
    int mid= start+ (end-start)/2;
    int c1= queryLazyMin(segTreeMin,lazy,2*idx+1,start,mid,l,r);
    int c2= queryLazyMin(segTreeMin,lazy,2*idx+2,mid+1,end,l,r);

    return min(c1,c2);

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> segTreeMin(4*n+1,-1);
    vector<int> lazy(4*n+1,0);

    buildSegTree(segTreeMin,arr,0,0,n-1);

    int q;
    cin>>q;

    while(q--){
        int x;
        cin>>x;
        
        //x==0 find the min in the range
        //x==1 update the given range with given increment
        if(x==0){
            int l,r;
            cin>>l>>r;

            int ans=queryLazyMin(segTreeMin,lazy,0,0,n-1,l,r);
            cout<<ans<<endl;
        }
        else if(x==1){
            int l,r,inc;
            cin>>l>>r>>inc;

            updateRangeLazy(segTreeMin,lazy,0,0,n-1,l,r,inc);
           
        }
    }
}