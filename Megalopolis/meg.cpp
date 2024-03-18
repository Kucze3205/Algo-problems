#include<bits/stdc++.h>
using namespace std;

const int MAXN = (1 << 19);
const int base = (1 << 19);

vector<int> Tri[MAXN];
int BinT[base << 1];

pair<int, int> tplg[MAXN]; //preorder, postorder
int preorder = 0;
vector<int> result;

void dfs(int v, int p, int deep){
    tplg[v].first = preorder;
    BinT[preorder + base] = deep;

    for(int w : Tri[v]){
        if(w == p) continue;

        preorder++;
        dfs(w, v, deep + 1);
        tplg[w].second = preorder;
    }
}

void upgrade(int a, int b, int val){
    a += base - 1;
    b += base + 1;

    while(a + 1 < b){
        if(a % 2 == 0) BinT[a + 1] += val;
        if(b % 2 == 1) BinT[b - 1] += val;
        a /= 2;
        b /= 2;
    }
}

int read(int v){
    v += base;
    int res = 0;
    while(v > 0){
        res += BinT[v];
        v /= 2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;

        Tri[a].push_back(b);
        Tri[b].push_back(a);
    }
    for(int i = 0; i < (base << 1); i++) BinT[i] = 0;

    dfs(1, 0, 0);

    int m;
    cin >> m;

    int time = n + m;


    while(--time){
        char c;
        cin >> c;

        if(c == 'W'){
            int v;
            cin >> v;
            result.push_back(read(tplg[v].first));
        }else{
            int a, b;
            cin >> a >> b;

            upgrade(tplg[b].first, tplg[b].second, -1);
        }

        //for(int i = 1; i <= n; i++) cout << tplg[i].first << " " << tplg[i].second << " " << BinT[tplg[i].first] << "\n";
        //cout << "\n";
    }

    for(int r : result) cout << r << "\n";

    return 0;
}
