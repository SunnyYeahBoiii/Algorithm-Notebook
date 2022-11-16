struct PalindromeTree{
    static const int MAXNODE = 1000010;
    string s;

    struct Node{
        int start = -1 , end = -1;
        int len = 0;
        int nxt[26];
        int pre;
        int num = 0;
    } tree[MAXNODE];    
    int num = 2;
    int current = 2;

    void init(string x){
        tree[1].len = -1;
        tree[2].len = 0;
        tree[1].pre = 1;
        tree[2].pre = 1;
        s = x;
    }

    void insert(int pos){
        int curNode = current;
        int x = s[pos] - 'a';
        while(true){
            int len = tree[curNode].len;
            if(pos - len - 1 >= 0 && s[pos - len - 1] == s[pos])
                break;
            curNode = tree[curNode].pre;
        }

        if(tree[curNode].nxt[x] != 0){
            current = tree[curNode].nxt[x]; 
            return;
        }
    
        num++;
        tree[num].start = pos - tree[curNode].len - 1;
        tree[num].end = pos;
        tree[num].len = tree[curNode].len + 2;
        tree[num].num = 1;
        tree[curNode].nxt[x] = num;
        current = num;
        
        if(tree[num].len == 1){
            tree[num].pre = 2;
            return;
        }

        curNode = tree[curNode].pre;

        while(true){
            int len = tree[curNode].len;
            if(pos - len >= 0 && s[pos - len - 1] == s[pos])
                break;
            curNode = tree[curNode].pre;
        }

        tree[num].pre = tree[curNode].nxt[x];
        tree[num].num = 1 + tree[tree[num].pre].num;
    }
};
