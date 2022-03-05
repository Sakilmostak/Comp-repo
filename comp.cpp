#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m=nums2.size();
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }

        int start=0;
        int end=n;
        while(start<=end){
            int mid= (start+end)/2;
            int elemrem= (n+m+1)/2 - mid;

            int l1= (mid==0)? INT_MIN: nums1[mid-1];
            int l2= (elemrem==0)? INT_MIN: nums2[elemrem-1];

            int r1= (mid==n)? INT_MAX: nums1[mid];
            int r2= (elemrem==m)? INT_MAX: nums2[elemrem];

            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0){
                return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else{
                    return max(l1,l2);
                }
            }
            else if(l1>r2){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        return 0.0;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v1(n),v2(m);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    for(int i=0;i<m;i++){
        cin>>v2[i];
    }

    cout<<findMedianSortedArrays(v1,v2);
}