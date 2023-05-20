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

// find the min in the given range
// Time comp: O(log(n))
// l=left range, r=right range
int queryMin(vector<int>& segTreeMin, int idx, int start, int end, int l, int r){
    if(end<l || start>r) return INT_MAX;
    if(start>=l && end<=r) return segTreeMin[idx];

    int mid= start+(end-start)/2;
    int c1= queryMin(segTreeMin,2*idx+1,start,mid,l,r);
    int c2= queryMin(segTreeMin,2*idx+2,mid+1,end,l,r);

    return min(c1,c2);
}

// update the given index
// Time comp: O(log(n))
// udx= index to update, increment= value to be increased by
void updateMin(vector<int>& segTreeMin, int idx, int start, int end, int udx, int increment){
    if(udx<start || udx>end) return;
    if(start==end &&  start==udx){
        segTreeMin[idx]+=increment;
        return;
    }

    int mid= start+(end-start)/2;
    updateMin(segTreeMin,2*idx+1,start,mid,udx,increment);
    updateMin(segTreeMin,2*idx+2,mid+1,end,udx,increment);

    segTreeMin[idx]= min(segTreeMin[2*idx+1],segTreeMin[2*idx+2]);
}

//update the given range
// Time coomp: O(n)
// l=left range, r=right range, increment= value to be increased by
void updateRangeMin(vector<int>& segTreeMin, int idx, int start, int end, int l, int r, int increment){
    if(start>r || end<l) return;
    if(start==end){
        segTreeMin[idx]+=increment;
        return;
    }

    int mid= start+(end-start)/2;
    updateRangeMin(segTreeMin,2*idx+1,start,mid,l,r,increment);
    updateRangeMin(segTreeMin,2*idx+2,mid+1,end,l,r,increment);

    segTreeMin[idx]= min(segTreeMin[2*idx+1],segTreeMin[2*idx+2]);

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

    buildSegTree(segTreeMin,arr,0,0,n-1);

    int q;
    cin>>q;

    while(q--){
        int x;
        cin>>x;
        
        //x==0 find the min in the range
        //x==1 update the given index with given increment
        //x==2 update the given range with given increment
        if(x==0){
            int l,r;
            cin>>l>>r;

            int ans= queryMin(segTreeMin,0,0,n-1,l,r);
            cout<<ans<<endl;
        }
        else if(x==1){
            int updateIndex, inc;
            cin>>updateIndex>>inc;

            updateMin(segTreeMin,0,0,n-1,updateIndex,inc);
        }
        else if(x==2){
            int l,r,inc;
            cin>>l>>r>>inc;

            updateRangeMin(segTreeMin,0,0,n-1,l,r,inc);
        }
    }
}