#include<bits/stdc++.h>

using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]=1;
    }

    int start;
    int maxlength=0;

    for(int i=0;i<n;i++){
        if(mp[arr[i]]==1){
            if(mp[arr[i]-1]==1){
                continue;
            }
            else{

            int totalLength=1;
            int j=arr[i]+1;
            while(mp[j]==1){
                mp[j]=0;
                totalLength++;
                j++;
            }

            if(totalLength>maxlength){
                start=arr[i];
                maxlength=totalLength;
            }

            }
        }
    }

    vector<int> rans;
    rans.push_back(start);
    if(maxlength>1)
        rans.push_back(start+maxlength-1);
    

    return rans;
}


int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    cout << ans[0];
    if (ans.size() > 1) {
        cout << " " << ans[ans.size() - 1];
    }

    delete[] arr;
}