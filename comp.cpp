#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int i=1;
        while(i<n-1){
            int j=i-1;
            bool lh=0,rh=0;
            while(nums[i]==nums[j] && j>0){
                j--;
            }
            
            if(nums[i]==nums[j]){
                i++;
                continue;
            }
            else if(nums[j]!=nums[i]){
                if(nums[j]>nums[i]){
                    lh=0;
                }
                else{
                    lh=1;
                }
            }
            
            
            
            j=i+1;
            
            while(nums[i]==nums[j] && j<n-1){
                j++;
            }
            
            if(nums[i]==nums[j]){
                break;
            }
            else if(nums[i]!=nums[j]){
                if(nums[i]<nums[j]){
                    rh=0;
                }
                else{
                    rh=1;
                }
            } 
            
            if(!(lh^rh)){
                count++;
            }
            
            i=j;
        }
        
        return count;
    }

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<countHillValley(arr);
        
}