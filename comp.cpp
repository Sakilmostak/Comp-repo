#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int numcheck[1000001];

class query{
	public:
	int first,second,index;
};

bool comp(query a,query b){
	return a.second<b.second;
}

void update(int i, int value, int n, int* BIT){
	for(;i<=n;i+=(i&(-i))){
		BIT[i]+=value;
	}
}

int value(int i, int* BIT){
	int count=0;
	for(;i>0;i-=(i&(-i))){
		count+=BIT[i];
	}

	return count;
}

int main(){
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}

	int q;
	cin>>q;
	query* queries= new query[q];
	for(int i=0;i<q;i++){
		cin>>queries[i].first>>queries[i].second;
		queries[i].index=i;
	}

	sort(queries,queries+q,comp);

	int total=0;
	int k=0;
	int* BIT= new int[n+1]();
	for(int i=0;i<1000001;i++){
        numcheck[i]=-1;
    }
	int ans[q];

	for(int i=1;i<=n;i++){
		if(numcheck[arr[i]]!=-1){
			update(numcheck[arr[i]],-1,n,BIT);
		}
		else{
			total++;
		}

		update(i,1,n,BIT);
		numcheck[arr[i]]=i;

		while(k<q && queries[k].second==i){
			ans[queries[k].index]= total- value(queries[k].first-1,BIT);
			k++;
		}

	}

	for(int i=0;i<q;i++){
		cout<<ans[i]<<" "<<endl;
	}



}