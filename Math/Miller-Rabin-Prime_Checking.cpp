/*
SunnyYeahBoi
It's My Time To Shine Bois
*/
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define endl "\n"

int pow_mod(int a, int b , int MOD){
	if(b <= 0) return 1;
	if(b == 1) return a;

	int tmp = pow_mod(a , b / 2 , MOD);

	if(b % 2 == 0)	
		return (tmp * tmp) % MOD;
	else return (tmp * tmp) % MOD * a % MOD;
}

bool Test(int n , int t , int s , int d){
	int tmp = pow_mod(t , d , n);

	if(tmp == 1 || tmp == n - 1) return false;

	for(int i = 0 ; i < s ; i++){
		tmp = tmp * tmp % n;
		if(tmp == n - 1) return false;
	}

	return true;
}

bool Prime_Check(int x){
	if(x < 4) return x == 2 || x == 3;
	
	int back = x;

	x--;
	int s = 0;
	while(x % 2 == 0) x /= 2 , s++;

	// x - 1 = 2^s * d
	
	for(int i = 0 ; i < 40 ; i++){
		int t = 2 + (rand() %(back - 3));
		if(Test(back , t , s , x))
			return false;
	}

	return true;
}

void solve(){

}

signed main(){
    // freopen("a.inp" , "r" , stdin);
    // freopen("a.out" , "w" , stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	int t; cin >> t; while(t--)solve();
	return 0;
}

