#include<bits/stdc++.h>
using namespace std;

const int MAXNK = 3e5 + 7;
const int base = 1 << 19;

int Lim[MAXNK];
vector<int> NPoles[MAXNK];
pair<int, int> range[MAXNK];
int rain[MAXNK][3];
int res[MAXNK];

priority_queue<pair<int, int>> que;
vector<pair<int, int>> next_que;
int tree[base << 1];


void upgrade(int lo, int hi, int val){
    if(lo + 1 >= hi)
        return;
    if(lo % 2 == 0) tree[lo + 1] += val;
    if(hi % 2 == 1) tree[hi - 1] += val;

    upgrade(lo / 2, hi / 2, val);

}

int Pole_val(int x){

    //return (x != 1) ? tree[x] + Pole_val(x / 2) : tree[x];

    if(x == 1)
        return tree[x];
    else
        return tree[x] + Pole_val(x / 2);
}

int Nation_val(int a){
    int val = 0;
    for(int i = 0; i < NPoles[a].size(); i++){
        val += Pole_val(NPoles[a][i]);

    }
    return val;
}

void reset(){
    for(int i = 0; i < next_que.size(); i++)
        que.push(next_que[i]);

    for(int i = 0; i < (base << 1); i++) tree[i] = 0;
}

void Make_result(int n, int m, int k){

    do{
        int i = 1;
        next_que.clear();

        while(que.size()){
            int next_res = -que.top().first;
            int nation = que.top().second;
            que.pop();

            for(int j = i; j <= next_res; j++){
                if(rain[j][0] < rain[j][1])
                    upgrade(rain[j][0] - 1, rain[j][1] + 1, rain[j][2]);
                else{
                    upgrade(rain[j][0] - 1, base + m + 1, rain[j][2]);
                    upgrade(base, rain[j][1] + 1, rain[j][2]);
                }

                //cout << rain[j][2] << " " << j << "\n";
            }


            if(Nation_val(nation) < Lim[nation])
                range[nation].first = next_res + 1;
            else
                range[nation].second = next_res;

            res[nation] = (range[nation].first + range[nation].second) / 2;

            cout << nation << " " << Nation_val(nation) << "\n";

            if(range[nation].first + 1 < range[nation].second && res[nation] <= k){
                if(res[nation] > next_res)
                    que.push({-res[nation], nation});
                else{
                    next_que.push_back({-res[nation], nation});

                }

            }

            i = next_res;
        }

        reset();
    }while(next_que.size());
}

int main(){

    int n, m;
    cin >> n >> m;

    int x;
    for(int i = 1; i <= m; i++){
        cin >> x;
        NPoles[x].push_back(i + base);
    }

    for(int i = 1; i <= n; i++)
        cin >> Lim[i];

    int k;
    cin >> k;

    for(int i = 1; i <= n; i++){
        res[i] = (1 + k + 1) / 2;
        que.push({-res[i], i});
        range[i] = {1, k + 1};
    }

    for(int i = 1; i <= k; i++){
        cin >> rain[i][0] >> rain[i][1] >> rain[i][2];
        rain[i][0] += base;
        rain[i][1] += base;

    }

    Make_result(n, m, k);

    for(int i = 1; i <= n; i++){
        if(res[i] <= k) cout << res[i] << "\n";
        else cout << "NIE" << "\n";
    }

    return 0;
}
