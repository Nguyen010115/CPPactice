#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

void solve(ll n){
	vector<ll> divisors;
	if (n == 1){
		cout << 1 << endl << 1;
		return;
	}
	while (n % 2 == 0) 
    { 
        n = n/2; 
        divisors.pb(2);
    } 

	if (n>1){
		
	for (ll i = 3; i*i <= n; i = i+2){
		
		if (n%i == 0){
		while (n%i == 0 && n > 1){
			divisors.pb(i);
			n /= i;
			}	
		}
	}
	}
	
	if (n > 2) divisors.pb(n);
	

	ll lens = divisors.size(), divi = 1, cnt = 1;
	if (lens > 1) for (ll i = 0; i < lens-1;i++){
		if (i != (lens-2)){
			if (divisors[i] == divisors[i+1]) cnt++;
			else{
				if (cnt > 1) cout << divisors[i] << "^" << cnt << "*";
				else cout << divisors[i] << "*";
				divi*= (cnt+1);
				cnt = 1;
			}
		}
		else{
			if (divisors[i] == divisors[i+1]) {
				cnt++;
				cout << divisors[i] << "^" << cnt;
				divi *= (cnt+1);
			}
			else {
				if (cnt > 1) cout << divisors[i] << "^" << cnt << "*" << divisors[i+1];
				else cout << divisors[i] << "*" << divisors[i+1];
				divi = divi*(cnt+1)*2;
			}
		}
	}
	else {
		cout << divisors[0];
		divi = 2;
	}

	cout << endl << divi;
}

int main(){
	ll n; cin >> n;
	solve(n);
	
}
