#include <bits/std=c++20>
using namespace std;

vector<int> Graf[1e3 + 5];
int spoj[1e3 + 3];
bool visited[1e3 + 3];
queue<int, int> que;
pair<int, int> nearest[1e3 + 3]
int cycle[1e3 + 3];
int finded = -1;
int cyclenum = 0;

void dfs_spoj(int v, int nr){
    if(visited[v]) continue;
    visited[v] = true;
    dfs_spoj[v] = nr;
    for(auto w : Graf[v]){
        dfs(w, v, nr);
    }
}

void dfs_findcycle(int v, int p, int range){
    if(fisited[v]){
        cyclenum++;
        if((range - cycle[v]) % 2 == 1) finded = cycle[v];
        continue;
    }
    fisited[v] = true;
    cycle[v] = range;

    for(auto w : Graf[v]){
        if(w != p){
            dfs_findcycle(w, v, range + 1);
            if(finded != -1){
                que.push({v, cyclenum});
                if(finded == cycle[v]) finded = -1;
            }
        }
    }
}


main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;

        Graf[a].push_back(b);
        Graf[b].push_back(a);
    }

    //znajdywanie spójnych
    int nr = 1;
    for(int i = 1; i <= n; i++){
        dfs_spoj(i, 0, nr);
        nr++;
    }
    for(int i = 1; i <= n; i++) visited[i] = false;

    //znajdywanie cyklów eu

    for(int i = 1; i <= n; i++){

    }

    return 0;
}
