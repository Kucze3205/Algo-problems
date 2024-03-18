#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1<<18;
const int MAXM = 2e5 + 3;
const int MAXJLN = 20;

int infNum[MAXM];
int oldinfNum[MAXN];
pair<int, int> line[MAXN];
pair<int, int> order[MAXN];
int deep[MAXN];
int res[MAXN];
bool isActive[MAXN];
int jump[MAXN][MAXJLN];
vector<int> Tri[MAXN];
int BinT[MAXN << 1];

int  preorder = 0;

void update(int a, int b, int val){
    a += MAXN - 1;
    b += MAXN + 1;

    while(a + 1 < b){
        if(a % 2 == 0) BinT[a + 1] += val;
        if(b % 2 == 1) BinT[b - 1] += val;
        a /= 2;
        b /= 2;
    }
}

int read(int v){
    int res = 0;
    v += MAXN;
    while(v > 0){
        res += BinT[v];
        v /= 2;
    }
    return res;
}

void Dfs(int v, int p, int dep){
    order[v].first = preorder;
    deep[v] = dep;
    for(int w : Tri[v]){
        if(w != p){
            preorder++;
            Dfs(w, v, dep + 1);
            order[w].second = preorder;
        }
    }
}

int jumpFrom(int v, int x){
    for(int i = (1 << MAXJLN); i > 0; i /= 2){
        if(x >= i){
            v = jump[v][(int)log2(i)];
            x -= i;
        }
    }
    return v;
}

bool check(int v, int x){
    int jto = jumpFrom(v, x);
    if(deep[v] - deep[jto] == read(order[v].first) - read(order[jto].first))
        return true;
    else
        return false;
}

int BS(int l, int r, int v){
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(check(v, mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int FindRep(int v){
    return jumpFrom(v, BS(0, deep[v], v));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    jump[1][0] = 1;

    for(int i = 1; i < n; i++){
        int a, b;

        cin >> a >> b;
        if(a > b) swap(a, b);
        line[i] = {a, b};
        Tri[a].push_back(b);
        Tri[b].push_back(a);
        jump[b][0] = a;

    }
    for(int i = 1; i < MAXJLN; i++) for(int j = 1; j <= n; j++)
        jump[j][i] = jump[jump[j][i - 1]][i - 1];

    for(int i = 0; i <= n; i++){
        infNum[i] = 1;
        oldinfNum[i] = 0;
    }

    for(int i = 0; i < MAXN << 1; i++) BinT[i] = 0;
    Dfs(1, 0, 0);

    for(int i = 0; i < m; i++){
        int dex;
        cin >> dex;
        int a = line[dex].first, b = line[dex].second;

        int rep_a = FindRep(a);

        if(!isActive[dex]){

            infNum[rep_a] += infNum[b] - oldinfNum[dex];
            update(order[b].first, order[b].second, 1);

            isActive[dex] = true;
        }else{
            infNum[b] = infNum[rep_a];
            oldinfNum[dex] = infNum[b];
            update(order[b].first, order[b].second, -1);
            isActive[dex] = false;
        }
    }

    for(int i = 0; i < q; i++){
        cin >> res[i];
        res[i] = infNum[FindRep(res[i])];
        cout << res[i] << "\n";

    }

    return 0;
}

