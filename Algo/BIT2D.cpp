struct BIT2D{
    int size;
    vector<vector<int>> tree;

    void init(int x){
        size = x + 5;
        tree.resize(size+5 , vector<int>(size+5 , 0));
    }

    void update1D(int u , int v , int a){
        int idx = v;
        while(idx <= size){
            tree[u][idx] += a;
            idx += (idx & (-idx));
        }
    }

    void update(int u , int v , int a){
        int idx = u;
        while(idx <= size){
            update1D(idx , v , a);
            idx += (idx & (-idx));
        }
    }

    int get1D(int u , int y){
        int idx = y , res = 0;
        while(idx > 0){
            res += tree[u][idx];
            idx -= (idx & (-idx));
        }
        return res;
    }

    int get(int x , int y1 , int y2){
        int idx = x , res = 0;
        while(idx > 0){
            res += get1D(idx, y2) - get1D(idx , y1-1);
            idx -= (idx & (-idx));
        }
        return res;
    }
};
