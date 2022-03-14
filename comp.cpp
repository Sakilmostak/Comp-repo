#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0){
            return nums[0];
        }
        
        if(k==1){
            if(n<=1){
                return -1;
            }
            else{
                return nums[1];
            }
        }
        
        if(n==1){
            if(k%2==0){
                return nums[0];
            }
            
            return -1;
        }
        
        int maxele=INT_MIN;
        for(int i=0;i<min(k-1,n);i++){
            maxele= max(maxele, nums[i]);
        }
        
        if(k<n){
            return max(maxele, nums[k]);
        }
        
        return maxele;
    }
};