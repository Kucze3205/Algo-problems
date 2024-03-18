#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 3;
const int MAXJLN = 30;
int jump[MAXN][MAXJLN];
int spj[MAXN];
int cycle_l[MAXN];

bool vis1[MAXN];
bool vis2[MAXN];

pair<int, int> point[MAXN]; //odl do cyklu, wierzchołek połączenia z cyklem

bool cycle_end = false;
int spoj;

int wyn[MAXN];

void dfs_spoj(int v){
    if(vis1[v]){
        if(spj[v] != -1) spoj = spj[v];
        return;
    }
    vis1[v] = true;
    dfs_spoj(jump[v][0]);
    spj[v] = spoj;
}

void dfs_cycle(int v, int p){
    if(vis2[v]){
        point[v].second = 0;
        point[v].first = 0;
        cycle_l[spj[v]] = 1;

        return;
    }

    vis2[v] = true;

    dfs_cycle(jump[v][0], v);
    if(!cycle_end){
        if(point[v].second == 0){
            cycle_end = true;
            return;
        }
        cycle_l[spj[v]]++;
        point[v].first = 0;
        point[v].second = 1 + point[jump[v][0]].second;

    }
}

void dfs(int v){
    if(point[v].first >= 0){
        return;
    }
    //cout << jump[v][0];
    dfs(jump[v][0]);
    point[v] = {point[jump[v][0]].first + 1, point[jump[v][0]].second};

}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    int a, b;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> jump[i][0];


    for(int i = 1; i < MAXJLN; i++) for(int j = 1; j <= n; j++)
        jump[j][i] = jump[jump[j][i - 1]][i - 1];

    for(int i = 1; i <= n; i++){
        point[i] = {-1, -1};
        cycle_l[i] = 0;
        spj[i] = -1;
        vis2[i] = false, vis1[i] = false;
    }
    for(int i = 1; i <= n; i++){
        spoj = i;
        if(!vis1[i]) dfs_spoj(i);
    }
    for(int i = 1; i <= n; i++){
        cycle_end = false;
        if(!vis2[i] && cycle_l[spj[i]] == 0){
            dfs_cycle(i, i);

        }

    }

    for(int i = 1; i <= n; i++) if(point[i].first == -1) dfs(i);



    for(int i = 1; i <= q; i++){
        cin >> a >> b;

        if(spj[a] != spj[b] || (point[a].first == 0 && point[b].first > 0)) wyn[i] = -1;
        else if(point[a].first == 0 && point[b].first == 0){
            if(point[a].second >= point[b].second){
                wyn[i] = point[a].second - point[b].second;
            }else{
                wyn[i] = cycle_l[spj[a]] - point[b].second + point[a].second;
            }
        }else if(point[b].first == 0 && point[a].first > 0){

            wyn[i] = point[a].first;

            if(point[a].second >= point[b].second){
                wyn[i] += point[a].second - point[b].second;
            }else{
                wyn[i] += cycle_l[spj[a]] - point[b].second + point[a].second;
            }
        }else if(point[a].first < point[b].first || point[a].second != point[b].second) wyn[i] = -1;
        else{
            int jumpin = point[a].first - point[b].first;
            int x = jumpin;
            for(int i = (1 << MAXJLN); i > 0; i /= 2){
                if(x >= i){
                    a = jump[a][(int)log2(i)];
                    x -= i;
                }
            }
            if(a == b) wyn[i] = jumpin;
            else wyn[i] = -1;
        }
    }

    //for(int i = 1; i <= n; i++) cout << point[i].first << " " << point[i].second << "\n";
    //cout << "\n";
    for(int i = 1; i <= q; i++) cout << wyn[i] << "\n";

    return 0;
}
