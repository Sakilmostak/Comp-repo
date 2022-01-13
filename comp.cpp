#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

class warrior{
    public:
    ll strength;
    ll coward;
    int idx;
};

void buildtree(warrior arr[], warrior *tree, int start, int end, int treeidx){
    if(start==end){
        tree[treeidx]= arr[start];
        return;
    }

    int mid = (start+end)/2;
    buildtree(arr,tree,start,mid,2*treeidx);
    buildtree(arr,tree,mid+1,end,2*treeidx+1);

    if(tree[2*treeidx].strength==tree[2*treeidx+1].strength){
        if(tree[2*treeidx].coward<=tree[2*treeidx+1].coward){
            tree[treeidx]=tree[2*treeidx];
            return;
        }
        else{
            tree[treeidx]=tree[2*treeidx+1];
            return;
        }
    }
    else if(tree[2*treeidx].strength>tree[2*treeidx+1].strength){
        tree[treeidx]= tree[2*treeidx];
    }
    else{
        tree[treeidx]= tree[2*treeidx+1];
    }

}

warrior query(warrior* tree, int start, int end, int treeidx, int left, int right){
    
    if(right<start || left>end){
        warrior willgo;
        willgo.strength=INT64_MIN;
        willgo.coward=INT64_MAX;
        willgo.idx=-1;
        return willgo;
    }

    if(start>=left && end<=right){
        return tree[treeidx];
    }

    int mid= (start+end)/2;
    warrior ans1= query(tree,start,mid,2*treeidx,left,right);
    warrior ans2= query(tree,mid+1,end,2*treeidx+1,left,right);
    if(ans1.strength==ans2.strength){
        if(ans1.coward<=ans2.coward){
            return ans1;
        }
        else{
            return ans2;
            
        }
    }
    else if(ans1.strength>ans2.strength){
        return ans1;
    }
    else{
        return ans2;
    }
}

int main(){
    int n;
    cin>>n;
    warrior arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].strength;
        arr[i].idx=i;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].coward;
    }
    warrior* tree= new warrior[4*n];
    
    buildtree(arr,tree,0,n-1,1);

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        warrior ans = query(tree,0,n-1,1,l-1,r-1);
        cout<<ans.idx+1<<endl;
    }

    delete [] tree;

    


}