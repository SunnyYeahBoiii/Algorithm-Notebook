struct Node{
    Node* child[26];
    int cnt;

    Node(){
        for(int i = 0 ; i < 26 ; i++)
            child[i] = NULL;
            cnt = 0;
        }
};

Node root = Node();

void Insert(string s){
    int n = s.size();
    Node* cur = &root;
    for(int i = 0 ; i < n ; i++){
        int x = s[i] - 'a';
        if(cur -> child[x] == NULL)
            cur -> child[x] =new Node();
        cur = cur -> child[x];

    }
    ++cur -> cnt;
}

bool Find(string s){
    int n = s.size();
    Node* cur = &root;
    for(int i = 0 ; i < n ; i++){
        int x = s[i] - 'a';
        if(cur -> child[x] == NULL)
            return false;
        cur = cur -> child[x];
    }
    return true;
}
