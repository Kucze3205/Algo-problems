#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1003;

vector<int> Graf[MAXN];
bitset<MAXN> anc[MAXN];
bitset<MAXN> c_p[MAXN];
int city[MAXN];
bitset<MAXN> wyn[MAXN];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int ki;
        cin >> ki;
        anc[i][i] = 1;
        for(int j = 0; j < ki; j++){
            int v;
            cin >> v;
            Graf[i].push_back(v);
            anc[i][v] = 1;
        }
    }

    for(int i = 0; i <= n; i++){
        city[i] = -1;
    }

    int citynum = 1;
    for(int i = 1; i < n; i++){
        int somsiad_am = 0;
        for(int j = i + 1; j <= n; j++){
            if(anc[i] == anc[j]){
                if(city[i] != -1){
                    city[j] = city[i];
                    c_p[city[j]][i] = 1;
                }
                else if(city[j] != -1){
                    city[i] = city[j];
                    c_p[city[i]][j] = 1;
                }
                else{
                    city[i] = citynum;
                    city[j] = citynum;
                    c_p[citynum][i] = 1;
                    c_p[citynum][j] = 1;
                    citynum++;
                }
                somsiad_am++;
            }
        }
        if(somsiad_am == Graf[i].size()){
            city[i] = citynum;
            anc[i][i] = 0;
            c_p[citynum - 1][i] = 0;
            c_p[citynum][i] = 1;
            citynum++;
        }

        if(city[i] == -1){
            city[i] = citynum;
            c_p[citynum][i] = 1;
            citynum++;
        }
    }
    if(city[n] == -1){
        city[n] = citynum;
        c_p[citynum][n] = 1;
        citynum++;
    }

    for(int i = 1; i <= citynum - 1; i++){
        for(int j = 1; j <= n; j++){
            if(city[j] == i){
                continue;
            }
            bitset<1003> new_bitset = c_p[i];
            new_bitset &= anc[j];
            if(new_bitset == c_p[i]){
                wyn[i][city[j]] = 1;
                wyn[city[j]][i] = 1;
            }
        }
    }

    cout << citynum - 1 << "\n";
    for(int i = 1; i <= n; i++){
        cout << city[i] << " ";
    }
    cout << "\n";

    for(int i = 1; i < citynum - 1; i++){
        for(int j = i + 1; j <= citynum - 1; j++){
            if(wyn[i][j]) cout << i << " " << j << "\n";
        }
    }

    return 0;
