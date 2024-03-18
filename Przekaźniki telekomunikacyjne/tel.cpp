#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 3;
const int MAXM = 5e5 + 3;
const int base = 1 << 19;

long long Tab[base << 1];
pair<long long, long long> ciag[base << 1];
int q[MAXM][2];
int n, a, b;

vector<long long> result;

long long suma(long long s, long long ds, int p, int q){
    long long wyn = 0;
    wyn = (q - p) * (q - p + 1);
    wyn = wyn / 2;
    wyn *= ds;
    wyn += s * (q - p + 1);

    return wyn;
}

void push(int v, long long s, long long ds, int p, int q){
    int mid = (q + p + 1) / 2;

    Tab[v * 2] += suma(s, ds, p, mid - 1);
    Tab[v * 2 + 1] += suma(s + (mid - p) * ds, ds, mid, q);

    ciag[v * 2].first += s;
    ciag[v * 2].second += ds;

    ciag[v * 2 + 1].first += s + (mid - p) * ds;
    ciag[v * 2 + 1].second += ds;

    ciag[v] = {0, 0};
}

void update(int v, long long s, long long ds, int p, int q){
    if(q < a || p > b) return;
    if(a <= p && q <= b){
        Tab[v] += suma(s, ds, p, q);

        ciag[v].first += s;
        ciag[v].second += ds;
    }else{
        int l = v * 2, r = v * 2 + 1, mid = (q + p + 1) / 2;
        if(v < base) push(v, ciag[v].first, ciag[v].second, p, q);

        update(l, s, ds, p, mid - 1);
        update(r, s + (mid - p) * ds, ds, mid, q);


        Tab[v] = Tab[v * 2] + Tab[v * 2 + 1];

    }


}

void postaw(int x, long long s, long long ds){
    int maxdx = s / ds;
    a = (x - maxdx < 0) ? 0 : x - maxdx;
    b = x;

    update(1, s - x * ds, ds, 0, base - 1);

    a = x + 1;
    b = (x + maxdx > n - 1) ? n - 1 : x + maxdx;
    //cout << a << " " << b << "\n";
    update(1, (s - ds + ds * a), -ds, 0, base - 1);
}

void usun(int x, long long s, long long ds){
    int maxdx = s / ds;
    a = (x - maxdx < 0) ? 0 : x - maxdx;
    b = x;
    update(1, -(s - x * ds), -ds, 0, base - 1);

    a = x + 1;
    b = (x + maxdx > n - 1) ? n - 1 : x + maxdx;
    update(1, -(s - ds + ds * a), ds, 0, base - 1);
}

long long srednia(int v, int p, int q){
    if(q < a || p > b) return 0;
    if(a <= p && q <= b){
        return Tab[v];
    }else{
        int l = v * 2, r = v * 2 + 1, mid = (q + p + 1) / 2;
        if(v < base) push(v, ciag[v].first, ciag[v].second, p, q);

        return srednia(l, p, mid - 1) + srednia(r, mid, q);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> n >> m;

    for(int i = 0; i < base * 2; i++) Tab[i] = 0;

    for(int i = 0; i < m; i++){
        char T;
        cin >> T;

        if(T == 'P'){
            int x;

            cin >> x;
            x--;
            cin >> q[x][0] >> q[x][1];

            postaw(x, q[x][0], q[x][1]);

            //cout << Tab[1] << "\n";

        }else if(T == 'U'){
            int x;

            cin >> x;
            x--;

            usun(x, q[x][0], q[x][1]);
            q[x][0] = 0;
            q[x][1] = 0;

            //cout << Tab[base/(2*2) + 1] << "\n";

        }else{
            //cout << "xd\n";
            cin >> a >> b;
            a--;
            b--;

            result.push_back(srednia(1, 0, base - 1) / (b - a + 1));
        }
    }

    for(auto r : result) cout << r << "\n";

    return 0;
}
