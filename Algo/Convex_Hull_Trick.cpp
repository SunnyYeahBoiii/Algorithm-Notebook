// CHT MAX
struct Line{
    ll x , y;
    Line(){}
    Line(ll _x, ll _y){
        x = _x , y = _y;
    }
} line[MAXN];
int sz = 0;
 
ll val(Line a , int coord){
    return a.x * coord + a.y;
}
 
bool ok(Line& a){
    int u = sz;
    if(a.x == line[u].x) return false;
    if(u == 1) return true;
 
    return 1.0 * (line[u-1].y - a.y) / (a.x - line[u-1].x) >= 1.0 * (line[u - 1].y - line[u].y) / (line[u].x - line[u - 1].x);
}
 
void insert(Line a){
    while(sz > 0 && !ok(a)) sz--;
    line[++sz] = a;
}
 
int getMax(int coord){
    int l = 1 , r = sz - 1 , result = 0;
    while(l <= r){
        int mid = l + r >> 1;
        double M = 1.0 * (line[mid + 1].y - line[mid].y) / (line[mid].x - line[mid + 1].x);
        if(coord > M){
            l = mid + 1;
            result = mid;
        }else r = mid - 1;
    }
    return val(line[result + 1] , coord);
}

// CHT MIN
struct Line{
    int x , y;
    Line(){}
    Line(int _x , int _y){
        x = _x , y = _y;
    }
} line[MAXN];
int sz = 0;
 
bool ok(Line a){    
    int u = sz;
    if(u == 1) return true;
    return 1.0 * (a.y - line[u - 1].y) / (line[u - 1].x - a.x) >= 1.0 * (line[u].y - line[u - 1].y) / (line[u - 1].x - line[u].x);
}
 
void insert(Line a){
    while(sz > 0 && !ok(a)) sz--;
    line[++sz] = a;
}
 
int val(Line a , int coord){
    return a.x * coord + a.y;
}
 
int getMin(int coord){
    int l = 1 , r = sz - 1 , result = 0;
    while(l <= r){
        int mid = l + r >> 1;
        double M = 1.0 * (line[mid + 1].y - line[mid].y) / (line[mid].x - line[mid + 1].x);
        if(coord > M){
            l = mid + 1;
            result = mid;
        }else r = mid - 1;
    }
 
    return val(line[result + 1] , coord);
}
