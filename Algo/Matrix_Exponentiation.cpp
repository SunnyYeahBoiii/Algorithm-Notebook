int MOD;

struct matrix{
    long long a[2][2];
    matrix()
    {
        a[0][0]=0;
        a[0][1]=1;
        a[1][0]=1;
        a[1][1]=1;
    }
};

matrix operator * (matrix a , matrix b){
        matrix res;
        for(int i = 0 ; i <= 1 ; i++){
            for(int j = 0 ; j <= 1 ; j++){
                res.a[i][j] = 0;
                for(int k = 0 ; k <= 1 ; k++)
                    res.a[i][j] = (res.a[i][j] + a.a[i][k] * b.a[k][j]) % MOD;
            }
        }
    return res;
}

matrix powermod (matrix a, long long n)
{
    if (n==1)
        return a;
    if (n%2!=0)
        return powermod(a,n-1)*a;
    matrix tmp = powermod(a,n/2);
    return tmp*tmp;
}
