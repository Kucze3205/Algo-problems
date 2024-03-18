#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+3;
const int MAXQ = 2e5+3;

int dpMin[MAXN][MAXN];
int dpMax[MAXN][MAXN];
int sajz[MAXN];

pair<vector<int>, bool> Tree[MAXN];

void dfs_sajz(int v, int p){
    for(int w : Tree[v].first){
        if(w == p) continue;

        dfs_sajz(w, v);
        sajz[v] += sajz[w];
    }
}

void dfs_makedp(int v, int p){
    int rozp = 0;
    dpMin[v][1] = Tree[v].second;
    dpMax[v][1] = Tree[v].second;

    for(int w : Tree[v].first){
        if(w == p) continue;

        dfs_makedp(w, v);

        for(int i = sajz[v]; i >= 1; i--){
            for(int j = sajz[w]; j >= 1; j--){
                /*cout << v << " ";
                cout << w << " ";
                cout << i + j << " ";
                cout << i << " ";
                cout << j << " ";
                cout << dpMax[v][i + j] << " ";
                cout << dpMax[v][i] + dpMax[w][j] << "\n";
                */

                dpMin[v][i + j] = min(dpMin[v][i + j], dpMin[v][i] + dpMin[w][j]);
                dpMax[v][i + j] = max(dpMax[v][i + j], dpMax[v][i] + dpMax[w][j]);
            }
        }
        sajz[v] += sajz[w];
    }

    if(sajz[v] == 1){
        dpMin[v][1] = Tree[v].second;
        dpMax[v][1] = Tree[v].second;
        //cout << v << " " << dpMin[v][1] << "\n";
        return;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int v;
        cin >> v;
        Tree[i].first.push_back(v);
        Tree[v].first.push_back(i);
        sajz[i] = 1;
        for(int j = 1; j <= n; j++){
            dpMin[i][j] = INT_MAX;
            dpMax[i][j] = INT_MIN;
        }
    }
    string word;
    cin >> word;

    for(int i = 0; i < word.size(); i++){
        if(word[i] == 'C') Tree[i + 1].second = 1;
    }

    //dfs_sajz(1, 0);
    dfs_makedp(1, 0);

    //for(int i = 1; i <= n; i++) cout << sajz[i] << "\n";

    //for(int i = 1; i <= n; i++){
        //for(int j = 1; j <= n; j++){
            //cout << dpMax[i][j] << " ";
        //}
        //cout << "\n";
    //}

    while(q--){

        int v, c, s;
        cin >> v >> c >> s;

        if(s + c > sajz[v]) cout << "NOT COMPROMISED\n";
        else if(dpMin[v][c + s] <= c && c <= dpMax[v][c + s]) cout << "COMPROMISED\n";
        else cout << "NOT COMPROMISED\n";
    }

    return 0;
}
