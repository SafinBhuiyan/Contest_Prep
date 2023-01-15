#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main () {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif 
	//  Sieve of Eratosthenes with pre-computition
	ll N = 1e7+10;
	vector<ll> prime(N, 1);

	prime[0]=prime[1]=0;
	for(ll i = 2; i*i <=N; i++){
		if(prime[i] == 1){
			for(ll j = i*i; j <=N; j +=i){
				prime[j] = 0;
			}
		}
	}

	// user input and primality test
	int T;
	cin>>T;
	while(T--){
		int x;
		cin>>x;
		if(prime[x]){
			cout<<"Prime!\n";
		}else{
			cout<<"Not prime\n";
		}
	}

	return 0;
}