#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 3;
const int base = 1 << 19;

vector<int> Tree[MAXN];
vector<int> wyn;
pair<int, int> order[MAXN];
int myorder[MAXN];
queue<pair<int, int>> breath;
int p[MAXN];
int Tri[base << 1];

int read(int a, int b){
    a += base - 1;
    b += base + 1;
    int wyn = 0;

    while(a + 1 < b){
        if(a % 2 == 0) wyn += Tri[a + 1];
        if(b % 2 == 1) wyn += Tri[b - 1];
        a /= 2;
        b /= 2;
    }

    return wyn;
}

void update(int v, int val){
    v += base;
    while(v > 0){
        Tri[v] += val;
        v /= 2;
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

    int preorder = 1;
    myorder[1] = 1;

    breath.push({1, 0});
    while(breath.size()){
        auto[v, o] = breath.front();
        breath.pop();
        p[v] = o;
        order[v].first = preorder + 1;
        for(int w : Tree[v]){
            if(w == o) continue;

            preorder++;
            myorder[w] = preorder;
            breath.push({w, v});
        }
        order[v].second = preorder;
    }

    int m;
    cin >> m;
    int act_wyn = 1;

    while(m--){
        int z;
        cin >> z;

        if(z > 0){
            update(myorder[z], 1);

            int blocked_amount = 0;

            if(order[z].first <= order[z].second) blocked_amount = read(order[z].first, order[z].second);
            blocked_amount += read(myorder[p[z]], myorder[p[z]]);

            act_wyn += Tree[z].size() - 1 - blocked_amount;
        }
        else{
            update(myorder[-z], -1);
            z = -z;

            int blocked_amount = 0;
            if(order[z].first <= order[z].second) blocked_amount = read(order[z].first, order[z].second);
            blocked_amount += read(myorder[p[z]], myorder[p[z]]);
            act_wyn -= Tree[z].size() - 1 - blocked_amount;
        }
        wyn.push_back(act_wyn);
    }

    for(int i : wyn) cout << i << "\n";
}
