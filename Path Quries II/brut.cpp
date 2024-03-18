#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 3;

int value[MAXN];
vector<int> Tree[MAXN];
bool finded = false;
int maksval = -INT_MAX;

void dfs_find(int v, int p, int cel){
    if(v == cel){
        maksval = max(maksval, value[v]);
        finded = true;
        return;
    }
    for(int w : Tree[v]){
        if(w == p) continue;

        dfs_find(w, v, cel);
        if(finded){
            maksval = max(maksval, value[v]);
            break;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> value[i];
    }

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;

        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    while(q--){
        int type, a, b;
        cin >> type >> a >> b;

        if(type == 1){
            value[a] = b;
        }else{
            dfs_find(a, 0, b);
            cout << maksval << " ";
            finded = false;
            maksval = -INT_MAX;
        }
    }


}
