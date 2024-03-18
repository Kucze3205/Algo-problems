#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 3;
const int MAXM = 5e5 + 3;

long long Tab[MAXN];
int q[MAXM][2];
vector<long long> result;
int n;

void upgrade(int x, int s, int a){

    Tab[x] += s;
    s -= a;

    for(int dx = 1; s > 0; dx++){
        if(x + dx <= n) Tab[x + dx] += s;
        if(x - dx >= 1) Tab[x - dx] += s;
        s -= a;
    }
}

void usun(int x, int s, int a){
    Tab[x] -= s;
    s -= a;

    for(int dx = 1; s > 0; dx++){
        if(x + dx <= n) Tab[x + dx] -= s;
        if(x - dx >= 1) Tab[x - dx] -= s;
        s -= a;
    }
}

long long read_medium(int a, int b){
    long long medium = 0;

    for(int i = a; i <= b; i++) medium += Tab[i];

    medium = medium / (b - a + 1);

    return medium;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++) Tab[i] = 0;

    for(int i = 0; i < m; i++){
        char T;
        cin >> T;

        if(T == 'P'){
            int x, s, a;
            cin >> x;
            cin >> q[x][0] >> q[x][1];

            upgrade(x, q[x][0], q[x][1]);

        }else if(T == 'U'){
            int x;
            cin >> x;

            usun(x, q[x][0], q[x][1]);
        }else{
            int a, b;
            cin >> a >> b;

            result.push_back(read_medium(a, b));
        }
    }

    for(auto r : result) cout << r << "\n";

    return 0;
}
