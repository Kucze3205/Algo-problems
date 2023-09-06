#include<bits/stdc++.h>
using namespace std;

const int MAXN = 12e3;
const int PUSH_VAL = 3e4;
const int MAXS = 1 << 17;

vector<pair<pair<int, int>,int>> nugg;
int Broom[MAXS << 1]; //
int T_MAX[MAXS << 1]; //


void upgrade_Tree(int p, int k, int val, int w, int a, int b){
    if(p < a || k > b)
        return;
    else if(p > a && k < b){
        Broom[w] += val;
        T_MAX[w] += val;
    }else{
        int l = 2 * w, r = 2 * w + 1, mid = (a + b) / 2;


        upgrade_Tree(l, r, val, l, a, mid);
        upgrade_Tree(l, r, val, r, mid + 1, b);

        Broom[v] = max(Broom[l], Broom[r]);
    }
}

int main(){

    int s, w, n;

    cin >> s >> w;
    cin >> n;
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        x += PUSH_VAL;
        y += PUSH_VAL;
        nugg.push_back({{x, 1}, y});
        nugg.push_back({{x, -1}, y + w});
    }
    sort(nugg.begin(), nugg.end());

    for(int i = 0; i < n; i++){
        int x = nugg[i].first.first;
        int y = nugg[i].second;
        int val = nugg[i].first.second;


    }

    return 0;
}
