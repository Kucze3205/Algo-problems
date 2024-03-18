#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 3;
const int MAXQ = 5e5 + 3;
const int base = (1 << 19);

ll tri[base << 1]; // wartość, index(nie będzie się zmieniał w zależności od zapytania)
ll tri2[base << 1];
vector<int> p;
int n;

void push(int v){
    tri[v * 2] += tri2[v];
    tri[v * 2 + 1] += tri2[v];
    tri2[v * 2] += tri2[v];
    tri2[v * 2 + 1] += tri2[v];


    tri2[v] = 0;
}

void update(int v, int a, int b, ll val, int p, int k){
    if(k < a || b < p) return;
    else if(p >= a && k <= b){

        tri2[v * 2] += val;
        tri2[v * 2 + 1] += val;

        tri[v] += val;

    }else{
        int mid = (p + k + 1) / 2;

        push(v);

        update(v * 2, a, b, val, p, mid - 1);
        update(v * 2 + 1, a, b, val, mid, k);
        tri[v] = max(tri[v * 2], tri[v * 2 + 1]);

    }

}

ll read(int v){
    update(1, v, v, 0, 0, base - 1);
    cout << v << " " << tri[v + base] - (n - v + 1) << "\n";
    return tri[v + base] - (n - v + 1);
}

int BS_B(ll val){
    int l = 0, r = n;
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(read(mid) < val) l = mid + 1;
        else r = mid;
    }
    return r;
}

int BS_K(ll val){
    int l = 0, r = n;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(read(mid) > val) r = mid - 1;
        else l = mid;
    }
    return l;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> n >> q;
    int n_xd = n;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        p.push_back(a);
    }
    p.push_back(0);
    sort(p.begin(), p.end());

    for(int i = 1; i < base * 2; i++) {
        tri[i] = LLONG_MIN;
    }

    for(int i = 1; i < p.size(); i++){
        tri[i + base] = p[i] + (n - i + 1);
    }

    for(int i = base - 1; i > 0; i--){
        tri[i] = max(tri[i * 2], tri[i * 2 + 1]);
    }

    while(q--){
        char type;
        ll x, y;
        cin >> type;

        if(type == 'B'){
            cin >> x >> y;
            int first_good = BS_B(x);

            update(1, first_good, n, y, 0, base - 1);

        }else if(type == 'K'){
            cin >> x >> y;
            int last_good = BS_K(x);
            update(1, 1, last_good, -y, 0, base - 1);
        }else{
            ll P = tri[1] - n;
            //BS_B(P);
            //cout << (n - BS_B(P) + 1) << "--\n";
        }

        for(int i = 1; i < p.size(); i++){
            update(1, i, i, 0, 0, base - 1);
            cout << tri[i + base] << " ";
        }
        cout << "\n";

    }



    return 0;
}
