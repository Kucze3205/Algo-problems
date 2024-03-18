#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int base = (1 << 18);
const int MXJLN = 19;

int value[MAXN];
int sajz[MAXN];
int deep[MAXN];
vector<int> Tree[MAXN];
pair<int, int> order[MAXN];
int tri[base << 1];
int preorder = 0;
int mainP[MAXN];
//lca
int jump[MAXN][MXJLN + 1];
int countint = 0;

void dfs_sajz(int v, int p, int dep){
    deep[v] = dep;
    for(int w : Tree[v]){
        if(w == p) continue;
        dfs_sajz(w, v, dep + 1);
        sajz[v] += sajz[w];
    }
}

void dfs_heavy(int v, int p){
    int heavy_son;

    if(Tree[v].size() <= 1 && p != 0) return;
    else if(Tree[v].size() == 0) return;

    if(Tree[v][0] != p){
        heavy_son = sajz[Tree[v][0]];
    }else{
        heavy_son = sajz[Tree[v][1]];
        swap(Tree[v][0], Tree[v][1]);
    }

    for(int i = 0; i < Tree[v].size(); i++){
        int w = Tree[v][i];
        if(w == p) continue;
        if(sajz[w] > heavy_son){
            swap(Tree[v][0], Tree[v][i]);
            heavy_son = sajz[w];
        }
        dfs_heavy(w, v);
    }
}

void dfs_order(int v, int p, int heavy){
    preorder++;
    order[v].first = preorder;

    mainP[v] = heavy;

    if(Tree[v].size() <= 1 && p != 0){
        order[v].second = preorder;
        return;
    }
    else if(Tree[v].size() == 0){
        order[v].second = preorder;
        return;
    }

    dfs_order(Tree[v][0], v, heavy);
    order[v].second = preorder;

    for(int i = 1; i < Tree[v].size(); i++){
        int w = Tree[v][i];
        if(w == p) continue;
        dfs_order(w, v, w);
    }
}

int read(int a, int b){
    a += base - 1;
    b += base + 1;
    int wyn = -INT_MAX;
    while(a + 1 < b){
        if(a % 2 == 0) wyn = max(wyn, tri[a + 1]);
        if(b % 2 == 1) wyn = max(wyn, tri[b - 1]);

        a /= 2;
        b /= 2;
    }

    return wyn;
}

void update(int v, int val){
    v += base;
    tri[v] = val;
    v /= 2;
    while(v > 0){
        tri[v] = max(tri[v * 2], tri[v * 2 + 1]);
        v /= 2;
    }
}

int jumpto(int v, int x){
    for(int i = (1 << MXJLN); i > 0; i /= 2){
        if(x >= i){
            v = jump[v][(int)log2(i)];
            x -= i;
        }
    }
    return v;
}

int lca(int a, int b){
    if(deep[a] > deep[b]) swap(a, b);

    if(deep[a] != deep[b]) b = jumpto(b, deep[b] - deep[a]);
    if(a == b) return a;

    for(int i = MXJLN; i >= 0; i--){
        if(jump[a][i] != 0 && jump[a][i] != jump[b][i]){
            a = jump[a][i];
            b = jump[b][i];
        }
    }

    return jump[a][0];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> value[i];
        sajz[i] = 1;
    }

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;

        Tree[a].push_back(b);
        Tree[b].push_back(a);
        if(a > b) swap(a, b);
        jump[b][0] = a;
    }

    for(int i = 1; i < MXJLN; i++){
        for(int j = 2; j <= n; j++){
            jump[j][i] = jump[jump[j][i - 1]][i - 1];
        }
    }


    dfs_sajz(1, 0, 0);
    //dfs_heavy(1, 0);
    //dfs_order(1, 0, 1);

    for(int i = 1; i <= n; i++) update(order[i].first, value[i]);

    //for(int i = 1; i <= n; i++) cout << order[i].first << "\n";


    while(false){
        int type, a, b;
        cin >> type >> a >> b;

        if(type == 1){
            update(order[a].first, b);
            value[a] = b;
        }else{
            int _LCA = lca(a, b);
            int maksval = -INT_MAX;
            //cout << _LCA << "\n";
            //cout << a << " " << mainP[a] << "\n";
            //cout << b << " " << mainP[b] << "\n";
            for(int i = 0; i < 2; i++){
                while(a != _LCA){

                    if(a == mainP[a]){
                        maksval = max(maksval, value[a]);

                        a = jump[a][0];
                    }else if(deep[mainP[a]] > deep[_LCA]){
                        maksval = max(maksval, read(order[mainP[a]].first, order[a].first));
                        a = jump[mainP[a]][0];
                    }else{
                        maksval = max(maksval, read(order[_LCA].first, order[a].first));
                        a = _LCA;
                    }
                }
                a = b;
            }

            maksval = max(maksval, value[_LCA]);

            cout << maksval << " ";
        }
    }


}
