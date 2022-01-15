#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

class coder{
	public:
	int x;
	int y;
	int index;
};

bool comp(coder a, coder b){
	if(a.x==b.x){
		return a.y<b.y;
	}

	return a.x<b.x;
}

void update(int y, int* BIT){
	for(;y<=100000;y+=(y&(-y))){
		BIT[y]++;
	}
}

int query(int y,int* BIT){
	int count=0;
	for(;y>0;y-=(y&(-y))){
		count+=BIT[y];
	}

	return count;
}

int main(){

	int n;
	cin >> n;

	coder arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].x;
		cin>>arr[i].y;
		arr[i].index=i;
	}

	sort(arr,arr+n,comp);

	int *BIT= new int[100001]();

	int ans[n];

	for(int i=0;i<n;){
		int endidx=i;
		while(endidx<n && arr[i].x==arr[endidx].x && arr[i].y==arr[endidx].y){
			endidx++;
		}

		//query
		for(int j=i;j<endidx;j++){
			ans[arr[j].index]= query(arr[j].y,BIT);
		}

		//update
		for(int j=i;j<endidx;j++){
			update(arr[j].y,BIT);
		}

		i=endidx;
	}

	for(int i=0;i<n;i++){
		cout<<ans[i]<<endl;
	}

	
}