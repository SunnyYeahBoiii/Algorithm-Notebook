const int BASE = 37 , MAXP = 1e6 , MOD = 1e9 + 7;
int powBase[MAXP] , pref[MAXP] , dp[MAXP];

void doHash(){
    powBase[0] = 1;
    for(int i = 1 ; i < MAXP ; i++) powBase[i] = (powBase[i - 1] * BASE) % MOD;

    pref[0] = s[0] - 'a' + 1;
    for(int i = 1 ; i < s.size() ; i++) pref[i] = (pref[i - 1] * BASE + (s[i] - 'a' + 1)) % MOD;
}

int getHash(int l , int r){
    int sub;
    if(l == 0)
        sub = 0;
    else sub = pref[l - 1];
    return (pref[r] - sub * powBase[r - l + 1] + MOD * MOD) % MOD;
}
