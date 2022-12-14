struct LCA{
    vector<int> h;
    vector<vector<int>> par;
    vector<bool> passed;
 
    void init(int n){
        h.resize(n+1);
        par.resize(65 , vector<int>(n+1 , 0));
        passed.resize(n+1 , false);
        h[1] = 1;
        dfs(1);
        preCompute(n);
    }   
 
    void dfs(int u){
        passed[u] = true;
        for(auto v : edges[u]){
            if(!passed[v]){
                h[v] = h[u] + 1;
                dfs(v);
                par[0][v] = u;
            }
        }
    }
 
    void preCompute(int n){
        int k = log2(n);
        for(int i = 1 ; i <= k ; i++)
            for(int j = 0 ; j <= n ; j++)
                par[i][j] = par[i-1][par[i-1][j]];
    }
 
    int find(int u , int v){
        if(h[v] > h[u])
            swap(u , v);
 
        if(h[u] > h[v]){
            int dif = h[u] - h[v];
            bitset<64> x = dif;
            for(int i = 0 ; i < 64 ; i++)
                if(x[i] == 1) u = par[i][u];
        }
 
        if(u == v) return u;
 
        int k = log2(h[u]);
        for(int i = k ; i >= 0 ; i--){
            if(par[i][u] != par[i][v]){
                u = par[i][u];
                v = par[i][v];
            }
        }
 
        return par[0][u];
    }
 
    int go_up(int u , int k){
        bitset<64> x = k;
        for(int i =0 ; i < 64 ; i++) if(x[i] == 1) u = par[i][u];
        return u;
    }
};
