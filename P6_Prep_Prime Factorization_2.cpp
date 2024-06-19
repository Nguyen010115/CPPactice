#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main(){
	ll n, twop = 0, divi = 1; cin >> n;
	
	while (n % 2 == 0) 
    { 
        n = n/2; 
        twop++;
    } 
    if (twop) {
    	if (twop > 1) cout << "2^"  <<twop;
    	else cout << "2";
	}
	divi *= twop+1;
	
	if (n>1){
		if (twop) cout << "*";
	for (ll i = 3; i*i <= n; i = i+2){
		ll temp = 0;
		if (n%i == 0){
		
		while (n%i == 0 && n > 1){
			temp++;
			n /= i;
		}
		if (n > 1 && temp > 1) cout << i <<"^" << temp << "*";
		else if (n == 1 && temp > 1) cout << i <<"^" << temp;
		else if (n>1 && temp == 1) cout << i  <<"*";
		else cout << i;
		if (temp) divi *= (temp+1); 	
	}
	}
		if (n > 2) {
			cout << n;
			divi *= 2;
		}
	}
	cout << endl << divi;
}

