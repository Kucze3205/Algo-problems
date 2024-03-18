#include<bits/stdc++.h>
using namespace std;

const int MAXN = 25e4;
const int base = (1 << 18);

vector<int> Tri[MAXN];
int p[MAXN];
bool build[MAXN];

vector<int> result;

int read(int v){
    int res = 0;
    while(v > 1){
        if(!build[v]) res++;
        v = p[v];
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
        p[b] = a;
    }

    int m;
    cin >> m;

    int time = n + m - 1;


    while(--time){
        char c;
        cin >> c;

        if(c == 'W'){
            int v;
            cin >> v;
            result.push_back(read(v));
        }else{
            int a, b;
            cin >> a >> b;
            build[b] = true;
        }

        //for(int i = 1; i <= n; i++) cout << tplg[i].first << " " << tplg[i].second << " " << BinT[tplg[i].first] << "\n";
        //cout << "\n";
    }

    for(int r : result) cout << r<< "\n";

    return 0;
}
