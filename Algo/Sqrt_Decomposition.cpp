struct SegTree{
    int n , sz;
    vector<int> tree;
    SegTree(){
        n = 1e4+1;
        tree.resize(4*1e4+5 , 0);
    }

    void update(int x , int k){
        update(1 , 0 , n-1 , x , k);
    }

    void update(int vt , int l , int r , int x , int k){
        if(l == r){
            tree[vt] += k;
            return;
        }
        
        int mid = (l + r) >> 1;

        if(x <= mid)
            update(vt << 1 , l , mid , x , k);
        else update(vt << 1 | 1 , mid+1 , r , x , k);

        tree[vt] = tree[vt << 1] + tree[vt << 1 | 1];
    }

    int get(int k){
        return get(1 , 0 , n-1 , k);
    }

    int get(int vt , int l , int r , int x){
        if(r < x)
            return 0;
        
        if(l >= x)
            return tree[vt];

        int mid = (l + r) >> 1;

        return get(vt << 1 , l , mid , x) + get(vt << 1 | 1 , mid+1 , r , x);
    }
};

int sz;
vector<SegTree> block;

void init(int x){
    sz = x / BLOCK_SIZE + 5;
    block.resize(sz);
}

void update(int x , int k){
    int idx = x / BLOCK_SIZE;
    block[idx].update(a[x] , -1);
    block[idx].update(k , 1);
    a[x] = k;
}

int BruteForce(int l , int r , int k){
    int res = 0;
    for(int i = l ; i <= r ; i++)
        if(a[i] > k) ++res;
    //cout << "added" << res << endl;
    return res;
}

int get(int l , int r , int k){
    int idxLeft = (l + BLOCK_SIZE - 1) / BLOCK_SIZE;
    int idxRight = r / BLOCK_SIZE;

    if(idxLeft >= idxRight)
        return BruteForce(l , r , k);

    int res = 0;    
    for(int i = idxLeft ; i < idxRight ; i++){
        res += block[i].get(k + 1);
        //cout << i * BLOCK_SIZE << " in for " << i * BLOCK_SIZE + BLOCK_SIZE - 1 << " " << res << endl;
    }

    res += BruteForce(l , idxLeft * BLOCK_SIZE - 1 , k) + BruteForce(idxRight * BLOCK_SIZE , r , k);

    return res;
}
