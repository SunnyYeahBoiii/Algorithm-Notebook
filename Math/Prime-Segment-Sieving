long long l , r;
vector<bool> prime;

void solve(){
    cin >> l >> r;
    prime.resize(r - l + 1 , true);

    for(int i = 2 ; i * i <= r ; i++){
        for(int j = max(i * i , (l + i - 1) / i * i) ; j <= r ; j += i)
            prime[j - l] = false;
    }

    if(1 >= l)
        prime[1 - l] = false;

    int res = 0;
    for(int i = l ; i <= r ; i++)
        if(prime[i - l]) res++;
    
    cout << res << endl;
}
