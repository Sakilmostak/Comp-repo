#include<bits/stdc++.h>
using namespace std;

class school{
    public:
    int roll;
    int marks;
    string name;
    
    void fill(int r, int m, string n){
        roll=r;
        marks=m;
        name=n;
    }
};

bool compare(school a, school b){
    if(a.marks!=b.marks){
        return a.marks>b.marks;
    }
    
    return a.roll<b.roll;
}
    
int main()
{
    int n;
    cin>>n;
    school scp[n];
    for(int i=0;i<n;i++){
        string s;
        int a,b,c;
        cin>>s>>a>>b>>c;
        scp[i].fill(i+1,a+b+c,s);
    }
    
    sort(scp,scp+n,compare);
    
    for(int i=0;i<n;i++){
        cout<<i+1<<" "<<scp[i].name<<endl;
    }
	return 0;
}
