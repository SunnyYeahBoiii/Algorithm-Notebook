int n , m;
int num[1005];
vector<int> odds , edges[1005];
int adj[1005][1005];
stack<pair<int , int>> st;
int cur;
vector<int> p[1005];
bool vis[1005];

void dfsDe(int u){
    if(num[u] % 2 == 1) odds.push_back(u);
    vis[u] = true;
    for(auto v : edges[u]){
        if(!vis[v]){
            dfsDe(v);
        }
    }
}

void dfs(int u){
    for(int i = 1 ; i <= n ; i++){
        if((adj[u][i] & 1) > 0){
            adj[u][i] ^= 1;
            adj[i][u] ^= 1;
            dfs(i);
            st.push({i , 0});
        }

        if((adj[u][i] & 2) > 0){
            adj[u][i] ^= 2;
            adj[i][u] ^= 2;

            dfs(i);
            st.push({i , 1});
        }
    }
}

void EulerTour(){
    cin >> n >> m;
    int u , v , c , add = 0;
    for(int i = 0 ; i < m ; i++){
        cin >> u >> v;
        num[u]++;
        num[v]++;
        adj[u][v] = 1;
        adj[v][u] = 1;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for(int i = 1 ; i <= n ; i++) vis[i] = false;

    
        dfsDe(1);

        if(odds.size() > 0){
            for(int i = 2 ; i < (int)odds.size() - 1 ; i += 2){
                int u = odds[i];
                int v = odds[i+1];
                adj[u][v] |= 2;
                adj[v][u] |= 2;
            }   

            dfs(odds.front());
            st.push({odds.front() , 0});
            odds.clear();
        }
        else{
            dfs(1);
            st.push({1 , 0});
        }

        while(!st.empty()){
            if(st.top().second == 1) cur++;
            p[cur].push_back(st.top().first);
            st.pop();
        }
        cur++;

    cout << cur << endl;

    for(int i = 0 ; i < cur ; i++){
        cout << p[i].size() << " ";
        for(int j = 0 ; j < p[i].size() ; j++)
            cout << p[i][j] << " ";
        cout << endl;
    }
}
