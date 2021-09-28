#include<bits/stdc++.h>

using namespace std;

bool descending(pair<int,int> p1, pair<int,int> p2){
    return p1.first>p2.first;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> rect;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        rect.push_back(make_pair(x/2,y));
    }

    sort(rect.begin(),rect.end(),descending);
    long long area=0;
    int width=rect[0].second;

    for(int i=0;i<n-1;i++){
        int xwidth= rect[i].first-rect[i+1].first;
        if(rect[i].second>width){
            width=rect[i].second;
        }

        area+= (xwidth*width);
    }

    if(rect[n-1].second>width){
        width=rect[n-1].second;
    }

    area+= (width*rect[n-1].first);
    area*=2;

    cout<<area<<endl;

    /* for(int i=0;i<n;i++){
        cout<<rect[i].first<<" "<<rect[i].second<<endl;
    } */
}