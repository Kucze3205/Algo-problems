#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 3;
const int MAXM = 5e5 + 3;

vector<pair<int, int>> G[2 * MAXN]; //wierzchołek : sąsiad, numer pary
bool vis[2 * MAXN];
int last = 0;
bool finded = false;
vector<int> result;
pair<int, int> stosun[MAXN * 2];

void dfs_cycle(int v, int p){
    if(vis[v]){
        last = v;
        //cout << v << " " << p << "\n";
        return;
    }
    vis[v] = true;
    //if(v == 9) cout << p;
    for(auto w : G[v]){
        if(w.first == p) continue;
        dfs_cycle(w.first, v);
        if(last != 0){
            if(!finded) result.push_back(w.second);
            break;
        }
    }
        if(v == last)
            finded = true;
}

void CheckV(int v){
    if(stosun[v].first + stosun[v].second == G[v].size() - 1 && !vis[v]){
        pair<int, int> to;
        vis[v] = true;
        for(auto w : G[v]){
            if(!vis[w.first]){
                to = w;
                break;
            }
        }
        if(stosun[v].first % 2 == 0){
            result.push_back(to.second);
            stosun[to.first].first++;
        }
        else{
            stosun[to.first].second++;
            if(stosun[to.first].second >= G[to.first].size())
                finded = true;
        }

        CheckV(to.first);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int r, c;
    for(int i = 1; i <= m; i++){
        cin >> r >> c;
        c += n;

        G[r].push_back({c, i});
        G[c].push_back({r, i});
    }

    for(int i = 1; i <= n; i++){
        if(!finded && !vis[i]){
            dfs_cycle(i, 0);
            //cout << i << "\n";
        }
    }

    if(result.size() && finded){
        cout << "TAK" << "\n";
        cout << result.size() << "\n";
        for(auto v : result) cout << v << " ";

        return 0;
    }
    //graf jest bez cykli więc to jest las (w szczeglności drzewo)

    for(int i = 1; i <= 2 * n; i++){
        stosun[i] = {0, 0};
        vis[i] = 0;
    }
    finded = false;
    for(int i = 1; i <= 2 * n; i++){
        if(!G[i].size() || stosun[i].second >= G[i].size()){
            //cout << i << "\n";
            cout << "NIE" << "\n";
            return 0;
        }
        CheckV(i);
    }
    if(finded){
        cout << "NIE" << "\n";
        return 0;
    }

    if(result.size()){
        cout << "TAK" << "\n";
        cout << result.size() << "\n";
        for(auto v : result) cout << v << " ";

        return 0;
    }
    //cout << last << "\n";
    return 0;
}
