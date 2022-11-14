struct SegTree{
    int n , sz;
    vector<int> tree;

    void init(int x){
        n = x;
        sz = 4 * n + 1;
        tree.resize(sz , 0);
    }

    void update(int u , int x){
        update(1 , 1 , n , u , x);
    }

    void update(int vt , int l , int r , int u , int x){
        // cout << "ST1D : " << vt << " " << l << " " << r << " " << u << " " << x << endl;
        if(l == r){
            // cout << "ST1D updated : " << vt << " " << x << endl; 
            tree[vt] = x;
            // cout << tree[vt] << endl;
            return;
        }

        int mid = (l + r) / 2;

        if(u <= mid)
            update(vt * 2 , l , mid , u , x);
        else update(vt * 2 + 1 , mid + 1 , r , u , x);

        tree[vt] = max(tree[vt * 2] , tree[vt * 2 + 1]);
    }

    int get(int l , int r){
        return get(1 , 1 , n , l , r);
    }

    int get(int vt , int l , int r , int u , int v){
        if(l > v || r < u) return 0;
        // cout << "ST1D : " << vt << " " << tree[vt] << " " << l << " " << r << " " << u << " " << v << endl;
        if(u <= l && r <= v) return tree[vt];

        int mid = (l + r) / 2;

        return max(get(vt * 2 , l , mid , u , v) , get(vt * 2 + 1 , mid + 1 , r , u , v));
    }
};

struct SegTree2D{
    int n , sz;
    vector<SegTree> tree;

    void init(int x){
        n = x;
        sz = 4 * n + 1;
        tree.resize(sz);
        for(int i = 0 ; i < sz ; i++)
            tree[i].init(n);
    }

    void update(int x , int y , int k){
        update(1 , 1 , n , x , y , k);
    }

    void update(int vt , int l , int r , int x , int y , int k){
        // cout << vt << " " << l << " " << r << " " << x << " " << y << " " << k << endl;
        if(l == r){
            // cout << "updated on " << vt << " " << l << " " << r << endl;
            tree[vt].update(y , k);
            return;
        }
        int mid = (l + r) / 2;

        if(x <= mid)
            update(vt * 2 , l , mid , x , y , k);
        else update(vt * 2 + 1 , mid + 1 , r , x , y , k);

        for(int i = 0 ; i < tree[vt].sz ; i++)
            tree[vt].tree[i] = max(tree[vt * 2].tree[i] , tree[vt * 2 + 1].tree[i]);
    }

    int get(int lx , int rx , int ly , int ry){
        return get(1 , 1 , n , lx , rx , ly , ry);
    }

    int get(int vt , int l , int r, int lx , int rx , int ly , int ry){
        if(l > rx || r < lx) return 0;
        // cout << "ST2D : " << vt << " " << l << " " << r << " " << lx << " " << rx << endl;
        if(lx <= l && r <= rx){
            // cout << "get on " << vt << " " << l << " " << r << endl;
            return tree[vt].get(ly , ry);
        }
        int mid = (l + r) / 2;

        return 
        max(get(vt * 2 , l , mid , lx , rx , ly , ry) , get(vt * 2 + 1 , mid + 1 , r , lx , rx , ly , ry));
    }
};

/*
    Init(n) - Khởi tạo ST2D quản lý 1 matrix n * n

    Query (x , y) - > (u , v)
    ST2D.get(x , u , y , v)

    Update (x , y , k)
    ST2D.update(x , y , k)
    
    Update 1 Points at a time, Get Max Point at (x , y) -> (u , v)
*/
