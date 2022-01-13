#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

void buildtree(ll arr[], ll *tree, int start, int end, int treeidx){
    if(start==end){
        tree[treeidx]= arr[start];
        return;
    }

    int mid = (start+end)/2;
    buildtree(arr,tree,start,mid,2*treeidx);
    buildtree(arr,tree,mid+1,end,2*treeidx+1);

    tree[treeidx]= max(tree[2*treeidx],tree[2*treeidx+1]);

}

ll query(ll arr[], ll* tree, int start, int end, int treeidx, int left, int right){
    if(right< start || left> end){
        return -1;
    }

    if(left<=start && right>=end){
        return tree[treeidx];
    }

    int mid = (start+end)/2;
    ll ans1 = query(arr,tree,start,mid,2*treeidx,left,right);
    ll ans2 = query(arr,tree,mid+1,end,2*treeidx+1,left,right);
    return max(ans1,ans2);
}

int main(){
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll *tree= new ll[4*n];
    buildtree(arr,tree,0,n-1,1);

    ll q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        ll ans= query(arr,tree,0,n-1,1,l,r);
        cout<<ans<<endl;

    }

    delete [] tree;

}