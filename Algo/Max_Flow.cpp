int n , m , s , t;
int flow[1005][1005];
int lim[1005][1005];
vector<int> adj[1005];

int Q[100005] , st , ed; // queue
int par[1005];
bool vis[1005];

bool bfs(){
    for(int i = 1 ; i <= n ; i++){
        vis[i] = false;
        par[i] = -1;
    }

    st = 0 , ed = 0;
    Q[ed++] = s;

    while(st < ed){
        int u = Q[st++];
        vis[u] = true;

        for(auto v : adj[u]){
            if(vis[v] == false && flow[u][v] < lim[u][v]){
                par[v] = u;

                if(v == t)
                    return true;

                Q[ed++] = v;
            }
        }
    }

    return false;
}

void Find_Max_Flow(){
    cin >> n >> m >> s >> t;
    for(int i = 0 ; i < m ; i++){
        int u , v , c;
        cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        lim[u][v] = c;
    }

    //return;

    int maximumFlow = 0;

    while(bfs()){
        int mn = inf;

        int u = par[t] , v = t;
        while(u != -1){
            //cout << u << " " << v << endl;
            mn = min(mn , lim[u][v] - flow[u][v]);
            v = u;
            u = par[u];
        }

        u = par[t] , v = t;
        while(u != -1){
            flow[u][v] += mn;
            flow[v][u] -= mn;
            v = u;
            u = par[u];
        }

        maximumFlow += mn;
    }

    cout << maximumFlow << endl;
}
