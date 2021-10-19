#include<bits/stdc++.h>
using namespace std;

int lbs(int arr[], int n){
	int output[n];
    int outputacs[n];
    int outputdcs[n];
	int flag[n]={0};

	for(int i=0;i<n;i++){
		output[i]=1;
        outputacs[i]=1;
        outputdcs[i]=1;
		for(int j=i-1;j>=0;j--){
			int pans;
            if(arr[j]<arr[i]){
                pans=outputacs[j]+1;
                if(pans>outputacs[i]){
                    outputacs[i]=pans;
                }
            }
            if(arr[j]>arr[i]){
                pans=outputdcs[j]+1;
                if(pans>outputdcs[i]){
                    outputdcs[i]=pans;
                }
            }
			if(flag[j]==0 && arr[j]<arr[i]){
				pans=output[j]+1;
				if(pans>output[i]){
					output[i]=pans;
					flag[i]=0;
				}
			}
            else if(flag[j]==1 && arr[j]<arr[i]){
                pans=2;
                if(pans>output[i]){
                    output[i]=pans;
                    flag[i]=0;
                }
            }
			else if(flag[j]==1 && arr[j]>arr[i]){
				pans=output[j]+1;
				if(pans>output[i]){
					output[i]=pans;
					flag[i]=1;
				}
			}
			else if(flag[j]==0 && arr[j]>arr[i]){
				pans=output[j]+1;
				if(pans>output[i]){
					output[i]=pans;
					flag[i]=1;
				}
			}
            if(outputacs[j]+1>output[i] && arr[j]>arr[i]){
                output[i]=outputacs[j]+1;
                flag[i]=1;
            }
		}
	}
	int ans=0;
    int ans1=0;
    int ans2=0;
    for(int i=0;i<n;i++){
        ans= max(ans,output[i]);
        ans1=max(ans1,outputacs[i]);
        ans2= max(ans2,outputdcs[i]);
    }
    
    //cout<<ans1<<" "<<ans2<<endl;
    
    return max(ans,max(ans1,ans2));
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		int ans= lbs(arr,n);
		cout<<ans<<endl;
	}
}
