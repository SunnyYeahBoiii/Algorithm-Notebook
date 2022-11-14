struct DSU{ 
    vector<int> par;
    void init(int n){
        par.resize(n+1 , -1);
    }
 
    int root(int x){
        return (par[x] < 0) ? x : (par[x] = root(par[x]));
    }
 
    void uni(int x,  int y){
        x = root(x) , y = root(y);
        if(x == y)
            return;
        if(x > y) swap(x , y);
        par[x] += par[y];
        par[y] = x;
    }
 
    bool check(int x , int y){
        x = root(x) , y = root(y);
        return x == y;
    }
};
