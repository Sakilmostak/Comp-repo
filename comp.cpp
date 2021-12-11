#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define MAX 100001

vector<int>* Sieve(){
	bool primes[MAX];
	for(int i=2;i*i<MAX;i++){
		if(!primes[i]){
			for(int j=i*i;j<MAX;j+=i){
				primes[j]=1;
			}
		}
	}
	vector<int>* primenum = new vector<int>();
	primenum->push_back(2);
	for(int i=3;i<MAX;i+=2){
		if(!primes[i]){
			primenum->push_back(i);
		}
	}

	return primenum;
}

void printPrimes(ll l, ll r, vector<int>* & primes){
	bool isPrime[r-l+1]={0};

	for(int i=0;primes->at(i)*(ll)primes->at(i)<=r;i++){
		int currPrime = primes->at(i);
		ll base= (l/(currPrime))*currPrime;  //just smaller or equal value to l whose mod is 0
		if(base<l){
			base+=currPrime;
		}
		for(ll j=base;j<=r;j+=currPrime){
			isPrime[j-l]=1;
		}
		if(base == currPrime){  //if base itself is a prime number
			isPrime[base-l]=0;
		}
	}
    if(l==1){
        isPrime[0]=1;
    }

	for(ll i=0;i<=r-l;i++){
		if(!isPrime[i]){
			cout<<i+l<<" ";
		}
	}
    cout<<endl;
}

int main(){
	vector<int>* primes = Sieve();
	int t;
	cin>>t;
	while(t--){
		ll l,r;
		cin>>l>>r;
		printPrimes(l,r,primes);
	}
}