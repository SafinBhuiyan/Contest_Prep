#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N = 1e8+7;

vector<ll> spf(N, 0);


void smallestPrimeFactor(){
	
	spf[1] = 1;
	// firsty make SmallestPrimeFector for every nuber
	// for all even set spf 2 and for odd to be itself
	for(ll i = 2; i< N; ++i){
		if(i%2 == 0){
			spf[i] = 2;
		}else{
			spf[i] = i;
		}
	}

	for(ll i = 3; i*i < N; i++){
		if(spf[i] == i){
			for(ll j = i*i; j<N; j += i){
				if(spf[j] == j){spf[j] = i;}
			}
		}
	}
}

vector<ll> getFactorization(ll x){
	vector<ll> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
 

int main () {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif 
	

	// user input and primality test
	int T;
	cin>>T;
	smallestPrimeFactor();
	while(T--){
		ll x;
		cin>>x;
		vector <ll> p = getFactorization(x); 
	    for (ll i=0; i<p.size(); i++)
	        cout << p[i] << " ";
	    cout << endl;
	}

	return 0;
}