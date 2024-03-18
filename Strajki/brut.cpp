#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 3;

vector<int> Tree[MAXN];
bool closed[MAXN];
bool visited[MAXN];
vector<int> wyn;

void dfs(int v, int p){
    if(closed[v] || visited[v]) return;
    visited[v] = true;

    for(int w : Tree[v]){
        if(w == p) continue;

        dfs(w, v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;

        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    int m;
    cin >> m;

    while(m--){
        int z;
        cin >> z;
        if(z > 0) closed[z] = true;
        else closed[-z] = false;

        int act_wyn = 0;
        for(int i = 1; i <= n; i++){
            if(!visited[i] && !closed[i]){
                dfs(i, 0);
                act_wyn++;
            }
        }
        wyn.push_back(act_wyn);

        for(int i = 1; i <= n; i++) visited[i] = false;
    }

    for(int i : wyn) cout << i << "\n";
}
