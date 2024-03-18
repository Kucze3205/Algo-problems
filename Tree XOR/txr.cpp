#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5 + 5;
const int MAXT = 1e4 + 2;

vector<pair<int, int>> Tree[MAXN];
int a[MAXN];
int sajz[MAXN];
int result[MAXN];
int n;

void dfs_sajz(int v, int p, int xore){

    sajz[v] = 1;

    for(auto w : Tree[v]){
        if(w.first == p) continue;
        dfs_sajz(w.first, v, w.second);
        sajz[v] += sajz[w.first];
    }

    result[1] += sajz[v] * xore;

}

void dfs_liczwyn(int v, int p, int xore){
    result[v] = result[p];
    result[v] -= xore * (sajz[v] - (n - sajz[v]));

    for(auto w : Tree[v]){
        if(w.first == p) continue;

        dfs_liczwyn(w.first, v, w.second);
    }
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            result[i] = 0;

        }

        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;

            Tree[u].push_back({v, a[u]^a[v]});
            Tree[v].push_back({u, a[v]^a[u]});

        }
        sajz[1] = 1;
        for(auto v : Tree[1]){
            dfs_sajz(v.first, 1, v.second);
            sajz[1] += sajz[v.first];
        }

        for(auto v : Tree[1]){
            dfs_liczwyn(v.first, 1, v.second);
        }

        for(int i = 1; i <= n; i++){
            cout << result[i] << " ";
            Tree[i].clear();
        }
        cout << "\n";


    }

    return 0;
}
